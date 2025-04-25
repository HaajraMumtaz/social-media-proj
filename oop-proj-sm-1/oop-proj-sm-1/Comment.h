#pragma once
#include "User.h"
class Comment
{
private:
	string userId_;
	string text_;
public:
	Comment(const string id="",const string text="");
	~Comment();


};