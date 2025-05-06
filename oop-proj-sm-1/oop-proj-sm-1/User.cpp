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
		lPostArr_[i]->DisplayPost(window, font, height, width, num, displayArr);
	}
}
void User::DisplayPosts(RenderWindow& window, Font& font, int height, int width, int&num, DisplayLayout**& displayArr)
{
	for (int i = 0; i < numPosts_; i++)
	{
		oPostArr_[i]->DisplayPost(window, font, height, width, num, displayArr);
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
void User::AddPost(Date&current)
{

	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = oPostArr_[i];
	}
	tempArr[numPosts_] = new Post;

	tempArr[numPosts_++]->Input();
	delete[]oPostArr_;
	oPostArr_ = tempArr;
}
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
void User::ShareMemory(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	string memoryId, desc;
	cout << "enter id:";

	getline(cin,memoryId);
	for (int i = 0; i < numPosts_; i++)
	{
		if (memoryId == (oPostArr_[i]->GetId()))
		{
			cout << "what message to display with it?";
			getline(cin,desc);
			oPostArr_[i]->DisplayPost(window, font, height, width, num,displayArr);
		}
	}
}
void User:: LikePage(Page** pagearr, int totalpages)
{

	
	cout << "enter id of page you want to like:";
	string id;
	getline(cin, id);
	bool found = 0;
	for (int i = 0; i < totalpages&&!found; i++)
	{
		if (pagearr[i]->GetId() == id)
		{
			found = 1;
			Page** temp = new Page * [numLikedPages_ + 1];
			for (int i = 0; i < numLikedPages_; i++)
			{
				temp[i] = lPageArr_[i];
			}
			temp[numLikedPages_] = pagearr[i];
			numLikedPages_++;

			delete[]lPageArr_;
			lPageArr_ = temp;
		}
	}


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
			oPostArr_[j]->DisplayPost(window,font,height, width, num,displayArr);
		}
	}
	return exists;

}
string User:: GetId()
{
	cout << "name:" << name_ << endl;
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
void User::DisplayFriends(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	DisplayLayout** temp = new DisplayLayout * [numFriends_ + numLikedPages_ + 1];
	

	temp[0] = displayArr[0];
	
	delete[]displayArr;

	displayArr = temp;
	for (int i = 0; i < numFriends_; i++)
	{
		displayArr[i + 1] = new DisplayLayout(font, { displayArr[0]->getPosition().x,displayArr[0]->getPosition().y + (num * displayArr[0]->getSize().y) }, displayArr[0]->getSize());
		
		cout << friendsArr_[i]->GetId() + " : " + friendsArr_[i]->GetName() << endl;
		displayArr[i + 1]->setData(friendsArr_[i]->GetId(), "", "", friendsArr_[i]->GetName());
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
void User:: LikePage(Page* pageToLike)
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

	
}
void User::AddPost(Date& current, string id, string desc, string date, Post* original)
{
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = oPostArr_[i];
	}
	tempArr[numPosts_] = new Memory(original,id,desc,date);
	numPosts_++;
	delete[]oPostArr_;
	oPostArr_ = tempArr;
}