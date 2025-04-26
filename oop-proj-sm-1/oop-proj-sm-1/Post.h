#pragma once
#include "Page.h"
#include "Comment.h"
#include "Common.h"
class Post
{
private:
	string Id_;
	User** usersLiked_;
	Comment** commentsArr_;
	Date date_;
	int numberLikes_;
	int numberComments_;
	string description_;//can be an image path
public:
	Post();
	Post(string ID, string desc,int d, int m , int y);
	void AddComment(Comment&);
	string GetId();
	virtual void DisplayPost();
	void DisplayLikedUsers();
	void AddLike();
	bool ValidDate(Date&current);
	virtual ~Post();
};