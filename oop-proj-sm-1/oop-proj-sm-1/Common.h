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
	~Date();
};

class Comment
{
private:
	string userId_;
	string text_;
public:
	Comment(const string id = "", const string text = "");
	~Comment();


};

struct PostVisual
{
	RectangleShape* box;
	Text* label;

	PostVisual(RectangleShape* b, Text* l) : box(b), label(l) {}
};