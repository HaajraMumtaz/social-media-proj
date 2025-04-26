#pragma once
#include<cstring>
#include "Post.h"

class Activity: public Post

{
private:
	string type_;
	string value_;
public:
	Activity(const string type = "", const string value = "", string desc, string id, int d, int m, int y);
	void DisplayPost() override;
	~Activity()override;

};

class Memory :public Post
{

private:
	Post* originalPost_;
public:
	Memory(Post* original, string desc,string id,int d, int m , int y);
	void DisplayPost() override;
	~Memory();
};