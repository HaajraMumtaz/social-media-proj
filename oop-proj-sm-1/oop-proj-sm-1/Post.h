#pragma once
#include "Page.h"
#include "Comment.h"
class Post
{
private:
	string Id_;
	string** usersLiked_;
	Comment** commentsArr_;
	string date_;
	int numberLikes_;
	int numberComments_;
	string description_;
public:
	Post();
	Post(string ID, string desc, string date);
	void AddComment(Comment&);
	string GetId();
	virtual void DisplayPost();
	void DisplayLikedUsers();
	void AddLike();
	bool validDate();
	virtual ~Post();
};