#pragma once
#include "User.h"

class Page
{
private:
	string Id_;
	User* owner_;
	string title_;
	Post** postsArr_;
	int numLikes_;

public:
	Page(const string id="", User* owner=nullptr,const string title="", Post** postarr = nullptr, int numlikes = 0);
	string GetId();
	void DisplayPosts();
	int GetNumLikes();
	void AddLike();
	void DisplayName();
	~Page();


};
