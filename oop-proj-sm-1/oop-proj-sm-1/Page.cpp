#include "Page.h"
#include "Post.h"
#include "User.h"

Page::Page(const string id,User* owner, const string title, Post** postarr,int numlikes, int numposts)
{
	Id_ = id;
	owner_ = owner;
	title_ = title;
	postsArr_ = postarr;
	numLikes_=numlikes;
	numPosts_ = numposts;
}

string Page::GetId()
{
	return Id_;
}
void Page::DisplayPosts()
{
	for (int i = 0; i < numPosts_; i++)
	{
		postsArr_[i]->DisplayPost();
	}
}
int Page:: GetNumLikes()
{
	return numLikes_;
}
void Page::AddLike()
{
	numLikes_++;
}
void Page::DisplayName()
{
	cout << title_ << endl;
}
Page::~Page()
{
	for (int i = 0; i < numPosts_; i++)
	{
		delete[]postsArr_[i];
	}
	delete[]postsArr_;

}

void Page::AddPost()
{
	Post** temp = new Post*[numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		temp[i] = postsArr_[i];
	}
	cout << "enter id:";
	string id;
	getline(cin, id);
	string desc;
	cout << "enter description:";
	getline(cin, desc);
	cout << "enter date (dd/mm/yy)";
	string date;
	getline(cin, date);
	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 2));
	temp[numPosts_] = new Post(id, desc, day, month, year);
	postsArr_ = temp;
}

void Page::DisplayPage()
{
	cout << Id_ << " " << title_;
	owner_->DisplayDetails();
	DisplayPosts();
}

void Page::DisplayValidPosts(Date&current)
{
	for (int j = 0; j < numPosts_; j++)
	{
		if (postsArr_[j]->ValidDate(current))
		{
			postsArr_[j]->DisplayPost();
		}
	}
}