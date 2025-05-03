#pragma once
#include <cstring>
#include <string>
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
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
	void ViewLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape** toDrawArr, Text**& textDrawArr);
	void DisplayPosts(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void ViewTimeline(Date& current, RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void AddFriend(User*);
	void AddPost(Date&);
	void AddPost(Date& current, string id, string desc, string date);
	void ShareMemory(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void LikePage(Page** pagearr,int totalpages);
	void LikePage(Page*);
	int GetNumPosts();
	bool DisplayValidPosts(Date& current,RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void DisplayDetails();
	void ViewHome(Date& current, RenderWindow&window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void DisplayDetails(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void DisplayFriends(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void DisplayLikedPages(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	void DisplayLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	inline string GetName()
	{
		return name_;
	}
	inline int GetNumLikedPg()
	{
		return numLikedPages_;
	}
	~User();
};
