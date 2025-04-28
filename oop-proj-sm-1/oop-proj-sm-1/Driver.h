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
	void CreateUser();
	/*void AddPost(Post*);*/
	void CreatePage();
	void Run();
	~Driver();
};