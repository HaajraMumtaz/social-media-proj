#pragma once
#include<cstring>
#include "Post.h"

class Activity: public Post

{
private:
	string type_;
	string value_;
public:
	Activity(const string type = "", const string value = "", string desc="", string id="", int d=0, int m=0, int y=0);
	/*void setActivity(string type, string value);*/
	void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr) override;
	inline void setType(string type)
	{
		type_ = type;

	}
	inline void setValue(string value)
	{
		value_ = value;

	}
	inline string GetId()
	{
		return Post::GetId();
	}
	inline string getDesc()
	{
		if (this != nullptr)
			return (type_+" "+value_);
	}
	~Activity()override;

};

class Memory :public Post
{

private:
	Post* originalPost_;
public:
	Memory();
	/*void setPost(string id="", string desc="", string date="", Post* original=nullptr);*/
	Memory(Post*& original, string desc, string id, string date);
	void DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr) override;
	inline string getOriginalId()
	{
		return originalPost_->GetId();
	}
	inline string getOriginalDate()
	{
		return originalPost_->getDate();
	}
	inline string getOriginalDesc()
	{
		return originalPost_->getDesc();
	}
	inline string GetId()
	{
		return Post::GetId();
	}
	inline string getDesc()
	{
		if (this != nullptr)
			return Post::getDesc();
	}
	~Memory() override;
};