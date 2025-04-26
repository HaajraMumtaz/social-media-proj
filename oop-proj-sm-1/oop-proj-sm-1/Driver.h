#pragma once
#include "User.h" 
class Driver
{

private:
	User* loginUser_;
	User** allUsers_;
	Page** allPages_;
	int userCount_;
	int pageCount_;

public:
	Driver();
	void setLoginUser(User*);
	void createUser();
	void createPost();
	void createPage();
	void run();
	~Driver();
};