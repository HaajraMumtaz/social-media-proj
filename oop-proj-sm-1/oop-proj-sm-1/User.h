#pragma once
#include <cstring>
#include <string>
#include "Post.h"
#include "Activity.h"
using namespace std;
class User
{
private:
	string Id_;
	string Name_;
	Post** oPostArr_;
	int numPosts_;
	User** friendsArr_;
	int numFriends_;
	Page** lPageArr;
	Post** lPostArr_;
public:
	User();
	User(string id, string name);
	void ViewHome();
	void ViewLikedPages();
	void ViewLikedPosts();
	void DisplayPosts();
	void ViewTimeline();
	void AddFriend(User*);
	void AddPost();
	void ShareMemory();
	void LikePage();
	string GetId();
	~User();






};
