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
class DisplayLayout;
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
	void ViewLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayPosts(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void ViewTimeline(Date& current, RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void AddFriend(User*);
	void AddPost(Date&);
	void AddPost(Date& current, string id, string desc, string date);
	void AddPost(Date& current, string id, string desc, string date,string type, string value);
	void AddMemory(Date& current, string id, string ogID, string desc);
	void ShareMemory(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void LikePage(Page** pagearr,int totalpages);
	void LikePage(Page*);
	int GetNumPosts();
	bool DisplayValidPosts(Date& current,RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayDetails();
	void ViewHome(Date& current, RenderWindow&window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayDetails(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayFriends(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayLikedPages(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void DisplayLikedPosts(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	void AddActivity(const string& id,string date);
	inline string GetName()
	{
		return name_;
	}
	inline int GetNumLikedPg()
	{
		return numLikedPages_;
	}
	void setValue(string value);
	void setType(string type);
	Post* searchPost(string id,bool&found);
	~User();
};
