#include "User.h"
#include "Driver.h"
#include "Page.h"
#include "Post.h"
#include "Common.h"
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
void User::ViewTimeline(Date& current)
{
	for (int i = 0; i < numFriends_; i++)
	{
		friendsArr_[i]->DisplayValidPosts(current);
	}
	for (int i = 0; i <numLikedPages_; i++)
	{
		friendsArr_[i]->DisplayValidPosts(current);
	}
}
void User::AddFriend(User*friendptr)
{
	friendsArr_[numFriends_++] = friendptr;
}
void User::AddPost(Date&current)
{
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = oPostArr_[i];
	}
	tempArr[numPosts_] = new Post("p1", "sample post", current.GetDay(), current.GetMonth(), current.GetYear());
	oPostArr_ = tempArr;
}
void User::ShareMemory()
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
			oPostArr_[i]->DisplayPost();
		}
	}
}
void User:: LikePage(Page** pagearr, int totalpages)
{
	Page** temp = new Page * [numLikedPages_ + 1];
	for (int i = 0; i < numLikedPages_; i++)
	{
		temp[i] = lPageArr_[i];
	}
	cout << "enter id of page you want to like:";
	string id;
	getline(cin, id);
	bool found = 0;
	for (int i = 0; i < totalpages&&!found; i++)
	{
		if (pagearr[i]->GetId() == id)
		{
			found = 1;
			lPageArr_[i] = pagearr[i];
			numLikedPages_++;
		}
	}
}
int User::GetNumPosts()
{
	return numPosts_;
}
void User::DisplayValidPosts(Date&current)
{
	for (int j = 0; j < numPosts_; j++)
	{
		if (oPostArr_[j]->ValidDate(current))
		{
			oPostArr_[j]->DisplayPost();
		}
	}
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

	for (int i = 0; i < numPosts_; i++)
	{
		delete[]oPostArr_[i];
	}
	delete[]oPostArr_;

	for (int i = 0; i < numPosts_; i++)
	{
		delete[]friendsArr_[i];
	}
	delete[]friendsArr_;

	for (int i = 0; i < numPosts_; i++)
	{
		delete[]lPageArr_[i];
	}
	delete[]lPageArr_;
	for (int i = 0; i < numPosts_; i++)
	{
		delete[]lPostArr_[i];
	}
	delete[]lPostArr_;
}