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
	cout << "Page created " << Id_ << endl;
}

string Page::GetId()
{
	return Id_;
}
void Page::DisplayPosts(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	for (int i = 0; i < numPosts_; i++)
	{
		postsArr_[i]->DisplayPost(window, font, height, width, num, toDrawArr, textDrawArr);
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
	
	cout << "add page post:" << endl;
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = postsArr_[i];
	}
	tempArr[numPosts_] = new Post;

	tempArr[numPosts_++]->Input();
	delete[]postsArr_;
	postsArr_ = tempArr;
}

void Page::DisplayPage(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	cout << Id_ << " " << title_;
	owner_->DisplayDetails();
	DisplayPosts(current,window, font, height, width, num, toDrawArr, textDrawArr);
}

bool Page::DisplayValidPosts(Date& current, sf::RenderWindow& window,sf::Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	bool exists = 0;
	for (int j = 0; j < numPosts_; j++)
	{
		if (postsArr_[j]->ValidDate(current))
		{
			cout << "going in" << endl;
			exists = 1;
			postsArr_[j]->DisplayPost(window,font,height,width,num,toDrawArr, textDrawArr);
		}
	}
	return exists;
}