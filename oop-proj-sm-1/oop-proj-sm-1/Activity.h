#pragma once

#include "Post.h"

class Activity: public Post

{
private:
	string type_;
	string value_;
public:
	Activity(const string type = "", const string value = "");
	void DisplayPost() override;
	~Activity()override;

};