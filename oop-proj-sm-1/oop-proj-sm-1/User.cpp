#include "User.h"


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

void ViewHome();
void User::ViewLikedPages()
{
	for (int i = 0; i < numLikedPages_; i++)
	{
		lPageArr_[i]->DisplayName();
	}
}

void User::ViewLikedPosts()
{
	for (int i = 0; i < numLikedPosts_; i++)
	{
		lPostArr_[i]->DisplayPost();
	}
}
void User::DisplayPosts()
{
	for (int i = 0; i < numPosts_; i++)
	{
		oPostArr_[i]->DisplayPost();
	}
}
void User::ViewTimeline()
{
	for (int i = 0; i < numFriends_; i++)
	{
		
	}
}
void User::AddFriend(User*friendptr)
{
	friendsArr_[numFriends_++] = friendptr;
}
void AddPost()
{
	
}
void ShareMemory();
void LikePage();
int getNumPosts();
void User::displayValidPosts()
{
	for (int j = 0; j < numPosts_; j++)
	{
		if (oPostArr_[j]->validDate())
		{
			oPostArr_[j]->DisplayPost();
		}
	}
}
string GetId();
~User();