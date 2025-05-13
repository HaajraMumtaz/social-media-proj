#define _CRT_SECURE_NO_WARNINGS
#include "Common.h"

Date::Date()
{
	time_t now = time(0);
	tm* localTime = localtime(&now);

	day_ = localTime->tm_mday;
	month_ = localTime->tm_mon + 1;;
	year_=localTime->tm_year + 1900;
}

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
