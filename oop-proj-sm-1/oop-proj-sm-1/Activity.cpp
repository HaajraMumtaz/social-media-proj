#include <string>
#include <iostream>
#include "Activity.h"
#include "Post.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

Activity::Activity(const string type , const string value , string desc, string id, int d, int m, int y) :Post(id, desc, d, m, y)
{
	type_ = type;
	value_ = value;
	
}

void Activity::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr) {
	Post::DisplayPost(window, font, height, width, num, toDrawArr,textDrawArr);
	cout << "Type:" << type_ << "Value:" << value_;
}


Memory::Memory(Post* original, string desc,string id,int d, int m, int y):Post(id,desc,d,m,y)
{
	originalPost_ = original;
	
}
void Memory::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, RectangleShape**& toDrawArr, Text**& textDrawArr)
{
	Post::DisplayPost(window,font,  height, width, num, toDrawArr, textDrawArr);
	originalPost_->DisplayPost(window, font, height, width, num, toDrawArr, textDrawArr);
}
Activity::~Activity() = default;
Memory::~Memory() = default;