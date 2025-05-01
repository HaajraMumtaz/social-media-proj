#include "User.h"
#include "Driver.h"
#include "Page.h"
#include "Post.h"
#include "Common.h"

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

void User::ViewLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
{
	for (int i = 0; i < numLikedPosts_; i++)
	{
		lPostArr_[i]->DisplayPost(window, font, height, width, num, toDrawArr, textDrawArr);
	}
}
void User::DisplayPosts(RenderWindow& window, Font& font, int height, int width, int&num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	for (int i = 0; i < numPosts_; i++)
	{
		oPostArr_[i]->DisplayPost(window, font, height, width, num, toDrawArr,textDrawArr);
	}
}
void User::ViewTimeline(Date& current, RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	bool exists = 0;
	for (int i = 0; i < numFriends_; i++)
	{
		exists=friendsArr_[i]->DisplayValidPosts(current,window, font, height, width, num,toDrawArr,textDrawArr);
	}
	bool exists2 = 0;
	for (int i = 0; i <numLikedPages_; i++)
	{
		exists2=lPageArr_[i]->DisplayValidPosts(current,window, font, height, width,num,toDrawArr,textDrawArr);
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
void User::ShareMemory(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
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
			oPostArr_[i]->DisplayPost(window, font, height, width, num,toDrawArr,textDrawArr);
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
bool User::DisplayValidPosts(Date&current,RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	bool exists = 0;
	for (int j = 0; j < numPosts_; j++)
	{
		if (oPostArr_[j]->ValidDate(current))
		{
			exists = 1;
			oPostArr_[j]->DisplayPost(window,font,height, width, num,toDrawArr,textDrawArr);
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

void User::ViewHome(Date&current, sf::RenderWindow&window, Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
{
	DisplayValidPosts(current, window, font, height, width, num,toDrawArr,textDrawArr);
	

}