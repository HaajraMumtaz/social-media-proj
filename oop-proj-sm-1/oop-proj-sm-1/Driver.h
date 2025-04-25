#pragma once
#include "User.h" 
class Application
{

private:
	User* loginUser_;
	User** allUsers_;
	Page** allPages_;
	int userCount_;
	int pageCount_;

public:
	Application();
	void SetLoginUser(User*);
	User& CreateUser();
	Post& CreatePost();
	Page& CreatePage();
	void Run();
	~Application();
};