#pragma once
#include "User.h" 
//#include "Page.h"
#include "Common.h"
using namespace sf;
class User;
class Page;

class Driver
{

private:
	User* loginUser_;
	User** allUsers_;
	Page** allPages_;
	int userCount_;
	int pageCount_;
	Date currentDate_;
public:
	Driver();
	void SetLoginUser(User*);
	User* GetLoginUser();
	/*void CreateUser(RenderWindow& window,RectangleShape& popup,Font&font,int width, int height,Text&,Text&);*/
	void CreateUser(string id, string name);
	void CreateUser();
	/*void AddPost(Post*);*/
	void CreatePage();
	void Deallocate(Text**&, RectangleShape**&, DisplayLayout**&, int&num2, int&num);
	void Run();
	bool searchUnique(string);
	void handleHover(sf::Sprite& sprite, sf::Text& text, const sf::RenderWindow& window, float scaleOnHover = 1.02f);
	~Driver();
};