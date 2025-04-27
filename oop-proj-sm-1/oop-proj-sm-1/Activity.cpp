#include <string>
#include <iostream>
#include "Activity.h"
#include "Post.h"
using namespace std;

Activity::Activity(const string type , const string value , string desc, string id, int d, int m, int y) :Post(id, desc, d, m, y)
{
	type_ = type;
	value_ = value;
	
}

void Activity::DisplayPost(){
	Post::DisplayPost();
	cout << "Type:" << type_ << "Value:" << value_;
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
Activity::~Activity() = default;
Memory::~Memory() = default;