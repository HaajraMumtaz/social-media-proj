#include <string>
#include <iostream>
#include "Activity.h"
#include "Post.h"
#include"PopUpForm.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

Activity::Activity(const string type , const string value , string desc, string id, int d, int m, int y) :Post(id, desc, value)
{
	type_ = type;
	value_ = value;
	
}

void Activity::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num,DisplayLayout**&displayArr) {
	Post::DisplayPost(window, font, height, width, num, displayArr);
	cout << "Type:" << type_ << "Value:" << value_;
}


Memory::Memory(Post* original, string desc,string id,string date):Post(id,desc,date)
{
	originalPost_ = original;
	
}
void Memory::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{

	originalPost_->DisplayPost(window, font, height, width, num, displayArr);
}

Activity::~Activity() = default;
Memory::~Memory() = default;