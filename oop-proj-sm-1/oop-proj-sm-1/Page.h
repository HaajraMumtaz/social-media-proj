#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include <string>
#include "PopUpForm.h"
using namespace sf;
class User;
class Post;
class Date;
using namespace std;
class Page
{
private:
	string Id_;
	User* owner_;
	string title_;
	Post** postsArr_;
	int numLikes_;
	int numPosts_;

public:
	Page(const string id="", User* owner=nullptr, const string title="", Post** postarr=nullptr,int numlikes=0,int numposts=0);
	string GetId();
	void DisplayPosts(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	string GetNumLikes();
	void AddLike();
	void DisplayName();
	void AddPost();
	void AddPost(Date& current, string id, string desc, string date);
	void DisplayPage(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	bool DisplayValidPosts(Date& current, RenderWindow& window,Font& font, int height, int width, int& num, DisplayLayout**& displayArr);
	inline string GetName()
	{
		return title_;
	}
	Post* searchPost(string id, bool& found);
	void AddMemory(Date& current, string id, string ogID, string desc);
	void AddActivity(const string& id, string date);
	void setValue(string value);
	void setType(string type);
	~Page();


};
