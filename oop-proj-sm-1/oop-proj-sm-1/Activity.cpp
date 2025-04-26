#include "Activity.h"


Activity::Activity(const string type = "", const string value = "", string desc, string id, int d, int m, int y) :Post(id, desc, d, m, y)
{
	type_ = type;
	value_ = value;
	
}

void Activity::DisplayPost()
{
	Post::DisplayPost();
	cout << "Type:" << type_ << "Value:" << value_;
}
Activity::~Activity()
{
	Post::~Post();
}

Memory::Memory(Post* original, string desc,string id,int d, int m, int y):Post(id,desc,d,m,y)
{
	originalPost_ = original;
	
}
void Memory::DisplayPost()
{
	Post::DisplayPost();
	originalPost_->DisplayPost();
}
Memory::~Memory()
{
	Post::~Post();
}