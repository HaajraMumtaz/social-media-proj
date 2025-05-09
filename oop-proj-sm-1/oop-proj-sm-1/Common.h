#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
using namespace sf;


class Date
{
private:
	int day_;
	int month_;
	int year_;
public:
	Date(int d=0,int m=0,int y=0);
	int GetDay();
	int GetMonth();
	int GetYear();
	inline string getDate()
	{
		string date = to_string(this->day_) + "//" + to_string(this->month_);
		date = date + "//";
		date = date + to_string(this->year_);
		return(date);
	}
	~Date();
};

class Comment
{
private:
	string userId_;
	string text_;
public:
	Comment(const string id = "", const string text = "");
	inline string getComment() { return (userId_ + ":" + text_); }
	~Comment();


};

