#include "Common.h"



Date::Date(int d, int m , int y ) :day_(d), month_(m), year_(y){}
int Date::GetDay()
{
	return day_;
}
int Date::GetMonth() { return month_; }
int Date::GetYear() { return year_; }
Date::~Date() { day_ = month_ = year_ = 0; }


Comment::Comment(const string id, const string text)
{
	userId_ = id;
	text_ = text;
}
Comment::~Comment()
{
	userId_ = text_ = "";
}
