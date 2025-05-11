#pragma once
#include<cstring>
#include "Common.h"
class User;
class Comment;
class DisplayLayout;
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
	Post(string ID, string desc,string date);
	void Input();
	virtual void setPost(string id, string desc, string date);
	void SetDetails(const string**&);
	inline void setId(string id)
	{
		Id_ = id;
	}
	void AddComment(Comment&,int&);
	virtual string GetId();
	virtual void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayLikedUsers(Text**&arr,int& num2);
	void AddLike(User*& likee);
	void SetDate(int d,int m, int y);
	void setDate(string);
	bool ValidDate(Date&current);
	inline string getDate()
	{
		cout << "getting date" <<Id_<< endl;
		return(date_.getDate());
	}
	inline virtual string getDesc()
	{
		if (this != nullptr)
			return description_;
	}

	void getComments(RectangleShape**&,int&, Text**& textarr);
	void AddComment(string comment, string id);
	virtual ~Post();
};