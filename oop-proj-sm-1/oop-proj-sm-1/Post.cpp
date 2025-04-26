#include "Post.h"

string Post:: GetId()
{
    return Id_;
}
void Post::DisplayPost()
{
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