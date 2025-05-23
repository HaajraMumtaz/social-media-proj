#include "User.h"
#include "Driver.h"
#include "Page.h"
#include "Post.h"
#include "Common.h"
#include"Activity.h"
#include "PopUpForm.h"
using namespace sf;
User::User()
{
	id_ = "";
	name_ = "";
	oPostArr_=nullptr;
	numPosts_=0;
	friendsArr_=nullptr;
	numFriends_=0;
	lPageArr_=nullptr;
	lPostArr_=nullptr;
	numLikedPosts_ = 0;
	numLikedPages_ = 0;

}
User::User(const string id, const string name)
{
	id_ = id;
	name_ = name;
	oPostArr_ = nullptr;
	numPosts_ = 0;
	friendsArr_ = nullptr;
	numFriends_ = 0;
	lPageArr_ = nullptr;
	lPostArr_ = nullptr;
	numLikedPosts_ = 0;
	numLikedPages_ = 0;
}

void ViewHome()
{
	cout << "in home" << endl;
}
void User::ViewLikedPages()
{
	for (int i = 0; i < numLikedPages_; i++)
	{
		lPageArr_[i]->DisplayName();
	}
}

void User::ViewLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	for (int i = 0; i < numLikedPosts_; i++)
	{
		lPostArr_[i]->DisplayPost(window, font, height, width, num, displayArr,this->id_);
	}
}
void User::DisplayPosts(RenderWindow& window, Font& font, int height, int width, int&num, DisplayLayout**& displayArr)
{
	for (int i = 0; i < numPosts_; i++)
	{
		oPostArr_[i]->DisplayPost(window, font, height, width, num, displayArr,this->id_);
	}
}
void User::ViewTimeline(Date& current, RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	bool exists = 0;
	for (int i = 0; i < numFriends_; i++)
	{
		exists=friendsArr_[i]->DisplayValidPosts(current,window, font, height, width, num,displayArr);
	}
	bool exists2 = 0;
	for (int i = 0; i <numLikedPages_; i++)
	{
		exists2=lPageArr_[i]->DisplayValidPosts(current,window, font, height, width,num,displayArr);
	}
	if (!exists && !exists2)
	{
		cout << "No post to show!" << endl;
	}

}
void User::AddFriend(User*friendptr)
{
	User** temp = new User * [numFriends_ + 1];
	for (int i = 0; i < numFriends_; i++)
	{
		temp[i] = friendsArr_[i];
	}
	temp[numFriends_++]= friendptr;
	delete[]friendsArr_;
	friendsArr_ = temp;
}
//void User::AddPost(Date&current)
//{
//
//	Post** tempArr = new Post * [numPosts_ + 1];
//	for (int i = 0; i < numPosts_; i++)
//	{
//		tempArr[i] = oPostArr_[i];
//	}
//	tempArr[numPosts_] = new Post;
//
//	tempArr[numPosts_++]->Input();
//	delete[]oPostArr_;
//	oPostArr_ = tempArr;
//}
void User::AddPost(Date& current,string id, string desc, string date)
{

	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = oPostArr_[i];
	}
	tempArr[numPosts_] = new Post;

	tempArr[numPosts_++]->setPost(id, desc, date);
	delete[]oPostArr_;
	oPostArr_ = tempArr;
}
void User::AddActivity(const string& id,string date)
{
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = oPostArr_[i];
	}
	tempArr[numPosts_] = new Activity();

	tempArr[numPosts_]->setPost(id,"",date);
	delete[]oPostArr_;
	oPostArr_ = tempArr;
}


int User::GetNumPosts()
{
	return numPosts_;
}
bool User::DisplayValidPosts(Date&current,RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	bool exists = 0;
	for (int j = 0; j < numPosts_; j++)
	{
		if (oPostArr_[j]->ValidDate(current))
		{
			exists = 1;
			oPostArr_[j]->DisplayPost(window,font,height, width, num,displayArr,this->id_);
		}
	}
	return exists;

}
string User:: GetId()
{

	return id_;
}

void User::DisplayDetails()
{
	cout << id_ << "  " << name_;
}
User::~User()
{
	cout << "~user() called" <<this->id_<< endl;
	for (int i = 0; i < numPosts_; i++)
	{
		delete oPostArr_[i];
	}
	delete[]oPostArr_;

	delete[]friendsArr_;
	delete[]lPageArr_;
	delete[]lPostArr_;
}

void User::ViewHome(Date&current, sf::RenderWindow&window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	DisplayValidPosts(current, window, font, height, width, num,displayArr);
	

}
void User::DisplayFriends(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr,bool mark)
{
	DisplayLayout** temp;
	if(mark)
	temp = new DisplayLayout * [numFriends_ + numLikedPages_ + 1];
	else
	temp = new DisplayLayout * [numFriends_ + 1];

	temp[0] = displayArr[0];
	
	delete[]displayArr;

	displayArr = temp;
	for (int i = 0; i < numFriends_; i++)
	{
		displayArr[i + 1] = new DisplayLayout(font, { displayArr[0]->getPosition().x,displayArr[0]->getPosition().y + (num * displayArr[0]->getSize().y) }, displayArr[0]->getSize());
		
		cout << friendsArr_[i]->GetId() + " : " + friendsArr_[i]->GetName() << endl;
		displayArr[i + 1]->setData(friendsArr_[i]->GetId(), friendsArr_[i]->GetName(), "", "","Friend ID: ", "Friend Name: ", "", "");
		num++;
	}
}
void User::DisplayLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	DisplayLayout** temp = new DisplayLayout * [numLikedPosts_ + 1];

	temp[0] = displayArr[0];

	delete[]displayArr;

	displayArr = temp;
	for (int i = 0; i < numLikedPosts_; i++)
	{
		displayArr[i + 1] = new DisplayLayout(font, { displayArr[0]->getPosition().x,displayArr[0]->getPosition().y + (num * displayArr[0]->getSize().y) }, displayArr[0]->getSize());

	
		displayArr[i + 1]->setData(lPostArr_[i]->GetId(), lPostArr_[i]->getDesc(),"", "","Liked Post ID: ","Liked Post Desc:","","");
		num++;
	}
}
void User::DisplayDetails(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**&displayArr)
{
	DisplayFriends(window, font, height, width, num, displayArr);
	DisplayLikedPages(window, font, height, width, num, displayArr);
	cout << "size:" << numFriends_ + numLikedPages_ + 1 << endl;
	cout << "num liked" << numLikedPages_ << endl;
}

void User::DisplayLikedPages(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{

	for (int i =0; i < numLikedPages_;i++)
	{
		displayArr[num] = new DisplayLayout(font, { displayArr[0]->getPosition().x,displayArr[0]->getPosition().y + (num * displayArr[0]->getSize().y) }, displayArr[0]->getSize());
		displayArr[num]->setData(lPageArr_[i]->GetId(), lPageArr_[i]->GetName(), "","");
		num++;
	}
	
}
void User:: LikePage(Page*& pageToLike)
{
	
	Page** temp = new Page * [numLikedPages_ + 1];
	for (int i = 0; i < numLikedPages_; i++)
	{
		temp[i] = lPageArr_[i];
	}
	delete[]lPageArr_;
	lPageArr_ = temp;
	lPageArr_[numLikedPages_] = pageToLike;
	numLikedPages_++;
	pageToLike->AddLike();
	cout << "page:" << pageToLike->GetId() << " liked" << endl;

	
}
void User::AddMemory(Date& current, string id, string oldId, string desc)
{
	int j = 0;
	bool found = 0;
	Post** tempArr;
	for (j; j < numPosts_&&!found; j++)
	{
		if (oPostArr_[j]->GetId() == oldId)
			found = 1;
	}
	if (found)
	{
		tempArr = new Post * [numPosts_ + 1];
		for (int i = 0; i < numPosts_; i++)
		{
			tempArr[i] = oPostArr_[i];
		}
		tempArr[numPosts_] = new Memory(oPostArr_[j-1],id,desc,current.getDate());
		Memory* mem = dynamic_cast<Memory*>(tempArr[numPosts_]);
		cout << "added new memory:";
		if (mem)
		{
			cout << "id:" << mem->GetId() << "Desc:" << mem->getDesc() << "Date:" << tempArr[numPosts_]->getDate() << "Og ID:" <<
				mem->getOriginalId() << endl;
		}
		numPosts_++;
		delete[]oPostArr_;
		oPostArr_ = tempArr;
	}
}

void User::setType(string type)
{
	cout << "num this:" << numPosts_ << endl;
	Activity* mem = dynamic_cast<Activity*>(oPostArr_[numPosts_]);
	if (mem)
	{
		mem->setType(type);
	}
	else
		cout << "not type activity" << endl;

}
void User::setValue(string value)
{
	Activity* mem = dynamic_cast<Activity*>(oPostArr_[numPosts_]);
	if (mem)
	{
		mem->setValue(value);
		numPosts_++;
	}

	else
		cout << "not type activity" << endl;

}

Post* User::searchPost(string id,bool&found)
{

	for (int i = 0; i < numPosts_&&!found; i++)
	{
		if (oPostArr_[i]->GetId() == id)
		{
			found = 1;
			return (oPostArr_[i]);
		}
	}
	if (!found)
		return nullptr;
}
void User::likePost(Post*post)
{
	Post** temp = new Post * [numLikedPosts_ + 1];
	for (int i = 0; i < numLikedPosts_; i++)
	{
		temp[i] = lPostArr_[i];
	}
	delete[]lPostArr_;

	lPostArr_ = temp;
	lPostArr_[numLikedPosts_++] = post;
}

bool User::PageAlreadyLiked(Page*liked)
{
	bool unique = 1;
	for (int i = 0; i < numLikedPages_&&unique; i++)
	{
		if (lPageArr_[i] == liked)
			unique = 0;
	}
	return unique;
}
bool User::postAlreadyLiked(Post*liked)
{
	bool unique = 1;
	for (int i = 0; i <numLikedPosts_ && unique; i++)
	{
		if (lPostArr_[i] == liked)
			unique = 0;
	}
	return unique;
}
bool User::searchUnique(string id)
{
	bool unique = 1;
	if (this->id_ == id)
		return 0;
	for (int i = 0; i < numPosts_; i++)
	{
		if (oPostArr_[i]->GetId() == id)
			return 0;
	}
	return unique;
}