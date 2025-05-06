#pragma once
#include<cstring>
#include "Post.h"

class Activity: public Post

{
private:
	string type_;
	string value_;
public:
	Activity(const string type = "", const string value = "", string desc="", string id="", int d=0, int m=0, int y=0);
	void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr) override;
	~Activity()override;

};

class Memory :public Post
{

private:
	Post* originalPost_;
public:
	
	/*void setPost(string id="", string desc="", string date="", Post* original=nullptr);*/
	Memory(Post* original, string desc,string id,string date);
	void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr) override;
	~Memory() override;
};