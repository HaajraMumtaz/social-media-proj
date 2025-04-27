#pragma once
#include <cstring>
#include <string>
#include<iostream>
using namespace std;

class Post;
class Page;
class Date;
class User
{
private:
	string id_;
	string name_;
	Post** oPostArr_;
	int numPosts_;
	User** friendsArr_;
	int numFriends_;
	Page** lPageArr_;
	Post** lPostArr_;
	int numLikedPosts_;
	int numLikedPages_;
public:
	User();
	User(const string id, const string name);
	/*void ViewHome();*/
	string GetId();
	void ViewLikedPages();
	void ViewLikedPosts();
	void DisplayPosts();
	void ViewTimeline(Date& current);
	void AddFriend(User*);
	void AddPost(Date&);
	void ShareMemory();
	void LikePage(Page** pagearr,int totalpages);
	int GetNumPosts();
	void DisplayValidPosts(Date& current);
	void DisplayDetails();
	~User();
};
