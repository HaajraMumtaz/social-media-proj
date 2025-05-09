#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Post.h"
#include "Activity.h" 
#include "Common.h"
#include "PopUpForm.h"
string Post:: GetId()
{
    cout << "getting id"<<Id_<< endl;
    return Id_;
}
void Post::DisplayPost(RenderWindow& window, Font& font, int height, int width, int& num, DisplayLayout**& displayArr)
{
   

    cout << "num:" << num<<endl;
    DisplayLayout** temp = new DisplayLayout*[num + 1];
    for (int i = 0; i < num; i++)
    {
        temp[i] = displayArr[i];
       
    }
    cout << "testing:" << this->getDate() << "  " << this->GetId() << endl;
 /*   if (Memory* m = dynamic_cast<Memory*>(this))
    {
        cout << "display memory:" << endl;
        temp[num] = new DisplayMemory(font, { displayArr[0]->getPosition().x,displayArr[0]->getPosition().y + (num * displayArr[0]->getSize().y) }, displayArr[0]->getSize());
    }
    else if (Post* p=dynamic_cast<Post*>(this))*/
    
    cout << "display post:" << endl;
    temp[num] = new DisplayLayout(font, { displayArr[num-1]->getPosition().x,displayArr[num-1]->getPosition().y + (displayArr[num-1]->getSize().y) }, displayArr[0]->getSize());
    cout << "THIS DATE:" << this->date_.getDate() << endl;
    temp[num]->setData(this->Id_, this->description_, this->date_.getDate(), "");

    
  /*  temp[num]->setPosition(Vector2f(toDrawArr[0]->getPosition().x, temp[0]->getPosition().y +(num* temp[0]->getSize().y)));*/
    
    delete[]displayArr;
    displayArr = temp;
    num++;

    /*text.setPosition(window.getSize().x / 3.0f, (window.getSize().y /6.0f)+(num*textRect.height));*/
   
    /*window.draw(text);*/
    // Center the text
 
    //window.draw(*textDrawArr[num-1]);
    cout << "id:" << Id_ << "descrption:" << description_ << endl;
}
void Post:: DisplayLikedUsers(Text**&arr,int&num2)
{

    Text** temp = new Text * [numberLikes_ + 2];
    temp[0] = arr[0];
    delete[]arr;
    arr = temp;
    for (int i = 0; i < numberLikes_; i++)
    {
        arr[i + 1] = arr[i];
        arr[i + 1]->setPosition(arr[i]->getPosition().x, arr[i]->getPosition().y + 30);
        arr[i + 1]->setString(usersLiked_[i]->GetId());
        num2++;
    }
    cout << "array filled" << endl;
}
void Post::AddLike(User*&likee)
{
    bool alreadyLiked = 0;
    for (int i = 0; i < numberLikes_&&!alreadyLiked; i++)
    {
        cout << usersLiked_[i]->GetId() << "==" << likee->GetId()<< endl;
        if (usersLiked_[i]->GetId() == likee->GetId())
        {
            alreadyLiked = 1;
        }

    }
    User** temp;
    if (!alreadyLiked)
    {
        temp = new User * [numberLikes_ + 1];
        for (int i = 0; i < numberLikes_; i++)
        {
            temp[i] = usersLiked_[i];
        }
        delete[]usersLiked_;
        usersLiked_ = temp;
        usersLiked_[numberLikes_++] = likee;
        cout << "succesfully liked!" << endl;
    }
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
  
    delete[]usersLiked_;
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
Post::Post(string id, string description,string Date)
    :Id_(id), description_(description)
{
    this->setDate(Date);
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

void Post::AddComment(Comment& comment,int&num)
{
    Comment** temp;
    temp = new Comment* [numberComments_ + 1];
    for (int i = 0; i < numberComments_; i++)
    {
        temp[i] = commentsArr_[i];
    }
    temp[numberComments_] = &comment;
    commentsArr_ = temp;
    num++;

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

void Post::getComments(RectangleShape**& arr, int& num,Text**& textarr)
{
   
    RectangleShape** temp = new RectangleShape*[numberComments_ + 1];
    Text** texttemp = new Text * [numberComments_ + 1];
    temp[0] = arr[0];
    texttemp[0] = textarr[0];
    delete[]textarr;
    delete[]arr;
    arr = temp;
    textarr = texttemp;
    cout << "number comm:" << numberComments_ << endl;
    for (int i = 0; i < numberComments_; i++)
    {
        arr[i + 1] = arr[0];
        arr[i + 1]->setPosition({ arr[0]->getPosition().x,num*(arr[0]->getSize().y)+arr[0]->getPosition().y + 60 });
        textarr[i + 1] = textarr[0];
        textarr[i + 1]->setPosition({ textarr[0]->getPosition().x,num * (arr[0]->getSize().y)+textarr[0]->getPosition().y + 60 });
        textarr[i + 1]->setString(commentsArr_[i]->getComment());
        num++;

    }
}
void Post::AddComment(string comment, string id)
{
    Comment** temp = new Comment * [numberComments_ + 1];
    for (int i = 0; i < numberComments_; i++)
    {
        temp[i] = commentsArr_[i];
    }
    delete[]commentsArr_;
    commentsArr_ = temp;
    commentsArr_ [numberComments_] = new Comment(id, comment);
    numberComments_++;
    cout << "Added comment successfully!" << endl;


}
