#include "Page.h"
#include "Post.h"
#include "User.h"
#include "Activity.h"
Page::Page(const string id,User* owner, const string title, Post** postarr,int numlikes, int numposts)
{
	Id_ = id;
	owner_ = owner;
	title_ = title;
	postsArr_ = postarr;
	numLikes_=numlikes;
	numPosts_ = numposts;
	cout << "Page created " << Id_ << endl;
}

string Page::GetId()
{
	return Id_;
}
void Page::DisplayPosts(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	for (int i = 0; i < numPosts_; i++)
	{
		postsArr_[i]->DisplayPost(window, font, height, width, num, displayArr,this->Id_);
	}
}
string Page:: GetNumLikes()
{
	
	return (to_string(numLikes_));
}
void Page::AddLike()
{
	numLikes_++;
	cout << "num likes in f:" << numLikes_ << endl;
}
void Page::DisplayName()
{
	cout << title_ << endl;
}
Page::~Page()
{
	for (int i = 0; i < numPosts_; i++)
	{
		delete postsArr_[i];
	}
	delete[]postsArr_;

}

void Page::AddPost()
{
	
	cout << "add page post:" << endl;
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = postsArr_[i];
	}
	tempArr[numPosts_] = new Post;

	tempArr[numPosts_++]->Input();
	delete[]postsArr_;
	postsArr_ = tempArr;
}

void Page::DisplayPage(Date& current, RenderWindow& window, sf::Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	cout << Id_ << " " << title_;
	owner_->DisplayDetails();
	DisplayPosts(current,window, font, height, width, num,displayArr);
}

bool Page::DisplayValidPosts(Date& current, sf::RenderWindow& window,sf::Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
	bool exists = 0;
	for (int j = 0; j < numPosts_; j++)
	{
		if (postsArr_[j]->ValidDate(current))
		{
			cout << "going in" << endl;
			exists = 1;
			postsArr_[j]->DisplayPost(window,font,height,width,num,displayArr,this->Id_);
		}
	}
	return exists;
}
void Page::AddPost(Date& current, string id, string desc, string date)
{

	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = postsArr_[i];
	}
	tempArr[numPosts_] = new Post;

	tempArr[numPosts_++]->setPost(id, desc, date);
	delete[]postsArr_;
	postsArr_= tempArr;
}
Post* Page::searchPost(string id, bool& found)
{

	for (int i = 0; i < numPosts_ && !found; i++)
	{
		if (postsArr_[i]->GetId() == id)
		{
			found = 1;
			return (postsArr_[i]);
		}
	}
	if (!found)
		return nullptr;
}
void Page::setType(string type)
{
	cout << "num this:" << numPosts_ << endl;
	Activity* mem = dynamic_cast<Activity*>(postsArr_[numPosts_]);
	if (mem)
	{
		mem->setType(type);
	}
	else
		cout << "not type activity" << endl;

}
void Page::setValue(string value)
{
	Activity* mem = dynamic_cast<Activity*>(postsArr_[numPosts_]);
	if (mem)
	{
		mem->setValue(value);
		numPosts_++;
	}

	else
		cout << "not type activity" << endl;

}
void Page::AddMemory(Date& current, string id, string oldId, string desc)
{
	int j = 0;
	bool found = 0;
	Post** tempArr;
	for (j; j < numPosts_ && !found; j++)
	{
		if (postsArr_[j]->GetId() == oldId)
			found = 1;
	}
	if (found)
	{
		tempArr = new Post * [numPosts_ + 1];
		for (int i = 0; i < numPosts_; i++)
		{
			tempArr[i] = postsArr_[i];
		}
		tempArr[numPosts_] = new Memory(postsArr_[j - 1], id, desc, current.getDate());
		Memory* mem = dynamic_cast<Memory*>(tempArr[numPosts_]);
		cout << "added new memory:";
		if (mem)
		{
			cout << "id:" << mem->GetId() << "Desc:" << mem->getDesc() << "Date:" << tempArr[numPosts_]->getDate() << "Og ID:" <<
				mem->getOriginalId() << endl;
		}
		numPosts_++;
		delete[]postsArr_;
		postsArr_ = tempArr;
	}
}

void Page::AddActivity(const string& id, string date)
{
	Post** tempArr = new Post * [numPosts_ + 1];
	for (int i = 0; i < numPosts_; i++)
	{
		tempArr[i] = postsArr_[i];
	}
	tempArr[numPosts_] = new Activity();

	tempArr[numPosts_]->setPost(id, "", date);
	delete[]postsArr_;
	postsArr_ = tempArr;
}

bool Page::searchUnique(string id)
{
	bool unique = 1;
	if (this->Id_ == id)
		return 0;
	for (int i = 0; i < numPosts_; i++)
	{
		if (postsArr_[i]->GetId() == id)
			return 0;
	}
	return unique;
}