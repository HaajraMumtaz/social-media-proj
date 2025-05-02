#pragma once
#include<cstring>
#include "Common.h"
class User;
class Comment;
using namespace sf;

class Post
{
private:
	string Id_;
	User** usersLiked_;
	Comment** commentsArr_;
	int numberLikes_;
	Date date_;
	int numberComments_;
	string description_;//can be an image path
public:
	Post();
	Post(string ID, string desc,int d, int m , int y);
	void Input();
	void setPost(string id, string desc, string date);
	void SetDetails(const string**&);
	void AddComment(Comment&);
	string GetId();
	virtual void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**&toDrawArr,Text**& textDrawArr);
	void DisplayLikedUsers();
	void AddLike();
	void SetDate(int d,int m, int y);
	void setDate(string);
	bool ValidDate(Date&current);
	virtual ~Post();
};