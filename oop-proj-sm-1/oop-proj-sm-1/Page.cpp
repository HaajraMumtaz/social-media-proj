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
void Page::DisplayPosts(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
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
	delete[]postsArr_;
	postsArr_ = temp;
}

void Page::DisplayPage(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
{
	cout << Id_ << " " << title_;
	owner_->DisplayDetails();
	DisplayPosts(current,window, font, height, width, num, toDrawArr, textDrawArr);
}

bool Page::DisplayValidPosts(Date& current, sf::RenderWindow& window,sf::Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr)
{
	bool exists = 0;
	for (int j = 0; j < numPosts_; j++)
	{
		if (postsArr_[j]->ValidDate(current))
		{
			exists = 1;
			postsArr_[j]->DisplayPost(window,font,height,width,num,toDrawArr, textDrawArr);
		}
	}
	return exists;
}