#include <string>
#include <iostream>
#include "Activity.h"
#include "Post.h"
#include"PopUpForm.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

Activity::Activity(const string type , const string value , string desc, string id, int d, int m, int y) :Post(id, desc, value)
{
	type_ = type;
	value_ = value;
	
}

void Activity::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num,DisplayLayout**&displayArr) {
	Post::DisplayPost(window, font, height, width, num, displayArr);
	cout << "Type:" << type_ << "Value:" << value_;
}
Memory::Memory()
{
    originalPost_ = nullptr;
  
}

Memory::Memory(Post*& original, string desc,string id,string date):Post(desc,id,date)
{
    /*cout << "id:" << GetId() << " desc:" << desc << " date:" << date << "og id:" << original->GetId() << endl;*/
	originalPost_ = original;
	
}
void Memory::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{


    cout << "num:" << num << endl;
    DisplayLayout** temp = new DisplayLayout * [num + 1];
    for (int i = 0; i < num; i++)
    {
        temp[i] = displayArr[i];

    }
    temp[num] = new DisplayMemory(font, { displayArr[num-1]->getPosition().x,displayArr[num-1]->getPosition().y + (displayArr[0]->getSize().y) }, displayArr[0]->getSize());
    DisplayMemory* mem = dynamic_cast<DisplayMemory*>(temp[num]);
    if (!originalPost_)
    {
        cout << "original post is null" << endl;
    }
    if (mem) {
        cout << "display memory:" << endl;
        
        mem->setMemory(originalPost_->Post::getDate(), this->getDesc(), originalPost_->Post::GetId(), originalPost_->getDesc(), this->Post::getDate(),"");
        num++;
    }
    else {
        delete temp[num];
        std::cerr << "Error: temp[num] is not a DisplayMemory!" << std::endl;
    }

    delete[]displayArr;
    displayArr = temp;
  

    cout << "id:" << this->GetId() << "descrption:" << this->getDesc() << endl;

	/*originalPost_->DisplayPost(window, font, height, width, num, displayArr);*/
}

Activity::~Activity() = default;
Memory::~Memory() = default;