#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include <string>
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
	void DisplayPosts(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	int GetNumLikes();
	void AddLike();
	void DisplayName();
	void AddPost();
	void DisplayPage(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	bool DisplayValidPosts(Date& current, RenderWindow& window,Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr);
	inline string GetName()
	{
		return title_;
	}
	~Page();


};
