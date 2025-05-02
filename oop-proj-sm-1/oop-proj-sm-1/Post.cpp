#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Post.h"
#include "Common.h"
string Post:: GetId()
{
    return Id_;
}
void Post::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num,RectangleShape**& toDrawArr, Text**& textDrawArr)
{
   

    cout << "num:" << num<<endl;
    RectangleShape** temp = new RectangleShape*[num + 1];
    Text** temp2 = new Text* [num + 1];
    for (int i = 0; i < num; i++)
    {
        temp[i] = toDrawArr[i];
        temp2[i] = textDrawArr[i];
    }
    temp[num] = new RectangleShape(toDrawArr[0]->getSize());
    temp[num]->setPosition(Vector2f(toDrawArr[0]->getPosition().x, temp[0]->getPosition().y +(num* temp[0]->getSize().y)));
    temp2[num] = new Text;
    temp2[num]->setPosition(temp[num]->getPosition());
    temp2[num]->setString(description_);
    temp2[num]->setCharacterSize(40);
    temp2[num]->setFillColor(Color::Black);
    temp2[num]->setFont(font);
    delete[]textDrawArr;
    textDrawArr = temp2;
    delete[]toDrawArr;
    toDrawArr = temp;
    num++;

    /*text.setPosition(window.getSize().x / 3.0f, (window.getSize().y /6.0f)+(num*textRect.height));*/
   
    /*window.draw(text);*/
    // Center the text
 
    //window.draw(*textDrawArr[num-1]);
    cout << "id:" << Id_ << "descrption:" << description_ << endl;
}
void Post:: DisplayLikedUsers()
{
    for (int i = 0; i < numberLikes_; i++)
    {
        usersLiked_[i]->DisplayDetails();
    }
}
void Post::AddLike()
{
    numberLikes_++;
}
bool Post::ValidDate(Date&current)
{
    cout << "here" << endl;
    if ((date_.GetDay() >= current.GetDay() - 1 && date_.GetMonth() == current.GetMonth() && date_.GetYear() == current.GetYear())||(current.GetDay() == 1 && date_.GetMonth() == current.GetMonth() - 1 && date_.GetYear() == current.GetYear()))
    {
        return 1;
    }
    else if ((date_.GetYear() == (current.GetYear() - 1))&& (current.GetDay() ==1)&&(current.GetMonth()==1))
    {
        return 1;
    }
    return 0;


}
Post::~Post()
{
    cout << "~Post() called " << Id_ << endl;
    for (int i = 0; i < numberLikes_; i++)
    {
        delete[]usersLiked_[i];
    }
    delete[]usersLiked_;

    for (int i = 0; i < numberComments_; i++)
    {
        delete[]commentsArr_[i];
    }
    delete[]commentsArr_;
  
}

void Post::SetDate(int d,int m,int y)
{
    date_ = Date(d, m, y);
}
void Post::SetDetails(const string**&arr)
{
    Id_= *arr[0];
    description_ = *arr[1];
    SetDate(stoi(*arr[2]), stoi(*arr[3]), stoi(*arr[4]));

    
}
Post::Post(string id, string description,int d, int m, int y)
    :Id_(id), description_(description)
{
    date_= Date(d, m, y);
    usersLiked_ = nullptr;
    commentsArr_ = nullptr;
    numberLikes_ = 0;
    numberComments_ = 0;
}

Post::Post()
{
    usersLiked_ = nullptr;
    commentsArr_ = nullptr;
    numberLikes_ = 0;
    numberComments_ = 0;
    Id_ = "";
    description_ = "";
    date_ = Date();
}

void Post::AddComment(Comment& comment)
{
    Comment** temp;
    temp = new Comment* [numberComments_ + 1];
    for (int i = 0; i < numberComments_; i++)
    {
        temp[i] = commentsArr_[i];
    }
    temp[numberComments_] = &comment;
    commentsArr_ = temp;

}

void Post::Input()
{
    int d, m, y;
    cout << "enter id:";
    getline(cin, Id_);
    cout << "title:";
    getline(cin,description_);
    cout << "Date: enter day:";
    cin >> d;
    cout << "month:";
    cin >> m;
    cout << "year:";
    cin >> y;
    SetDate(d, m, y);

}
void Post:: setPost(string id, string desc, string date)
{
    Id_ = id;
    description_ = desc;
    setDate(date);
    cout << "added post "<<id << endl;
}

void Post::setDate(string date)
{
    string elem;
    int day=0, month=0, year=0;
    for (int i = 0; i < date.length();i++)
    {
        if (date[i] != '//')
        {
            elem = elem + date[i];
        }
        else
        {
            if (i <= 2)
                day = stoi(elem);
            else if (i <= 5)
                month = stoi(elem);
            else
                year = stoi(elem);
            i++;
           
        }
    }
    date_ = Date(day, month, year);
}