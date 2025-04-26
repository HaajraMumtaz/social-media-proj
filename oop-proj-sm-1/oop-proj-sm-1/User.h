#pragma once
#include <cstring>
#include <string>
#include<iostream>
#include "Post.h"
#include "Activity.h"
using namespace std;
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
	void ViewHome();
	string GetId();
	void ViewLikedPages();
	void ViewLikedPosts();
	void DisplayPosts();
	void ViewTimeline();
	void AddFriend(User*);
	void AddPost();
	void ShareMemory();
	void LikePage();
	int GetNumPosts();
	void DisplayValidPosts();
	void DisplayDetails();
	~User();
};
