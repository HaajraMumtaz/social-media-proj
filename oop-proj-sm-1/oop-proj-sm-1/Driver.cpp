#include <SFML/Graphics.hpp>
#include "Driver.h"
#include "Common.h"
#include "Page.h"
using namespace sf;

void Driver::Run()
{

    // Initializing variables & objects
    int width = 1280;
    int height = 720;
    RectangleShape rect1(Vector2f(100,100));
    Sprite but1;
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\button.png"))
    {
        cout << "unable to load" << endl;
    }
    Font font;
    if (!font.loadFromFile("D:\\haajra\\oop-proj\\additional-files\\GeistMonoBold.ttf"))
    {
        cout<<"cant load"<<endl;
    }
    float scaleFactor = min(width / buttonTexture.getSize().x, height / buttonTexture.getSize().y);
    but1.setScale(scaleFactor/3.5, scaleFactor/3.5);
    RenderWindow window(sf::VideoMode(width, height), "SFML Test");
    but1.setOrigin(Vector2f(0, 0));
    but1.setTexture(buttonTexture);
    but1.setPosition(30,height/3);
    Sprite but3 = but1;
    but3.setPosition(but1.getPosition().x, but1.getPosition().y + (height / 3));
    Sprite but2 = but1;
    but2.setPosition((but1.getPosition().x + but3.getPosition().x) / 2, (but1.getPosition().y + but3.getPosition().y) / 2);
    FloatRect boundingBoxB1 = but1.getGlobalBounds();
    FloatRect boundingBoxB2 = but2.getGlobalBounds();
    FloatRect boundingBoxB3 = but3.getGlobalBounds();
    int num = 1;
    RectangleShape** todraw=new RectangleShape*[1];
    todraw[0]=new RectangleShape(Vector2f(width/2,height/5));
    todraw[0]->setPosition(Vector2f(but1.getPosition().x + boundingBoxB1.width + 10, 0));
    todraw[0]->setOutlineColor(Color::White);
    todraw[0]->setOutlineThickness(10);
    Text** todrawtext = new Text*[1];
    todrawtext[0] = new Text;
    todrawtext[0]->setFillColor(Color::Black);
    todrawtext[0]->setPosition(todraw[0]->getPosition());
    todrawtext[0]->setCharacterSize(28);
   
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    CreateUser();
    CreateUser();
    CreatePage();
    allUsers_[0]->DisplayDetails();
    allUsers_[0]->AddFriend(allUsers_[1]);
    allUsers_[0]->LikePage(allPages_, pageCount_);
    allUsers_[1]->AddPost(currentDate_);
    allUsers_[1]->AddPost(currentDate_);
    allPages_[0]->AddPost();
    //allUsers_[1]->DisplayPosts();
    bool on = 0;
    while (window.isOpen()) {
   
        Event event;
        while (window.pollEvent(event)) {
            Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && boundingBoxB1.contains(mousePos)&&!on)
            {
                cout << "ok works" << endl;
                allUsers_[0]->ViewTimeline(currentDate_, window, font, height, width, num, todraw, todrawtext);
                on = 1;
                
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && boundingBoxB2.contains(mousePos))
            {
                on = 0;
                num = 1;
            }
        }

        window.clear(Color::Black);

        window.draw(but1);


        window.draw(but2);
        window.draw(but3);
        /*  window.draw(*todraw[0]);*/
      
        if (on)
        {
            for (int i = 1; i < num; i++)
            {
                window.draw(*todraw[i]);
                window.draw(*todrawtext[i]);
            
            }
        }
       
        window.display();
    }
    
}

void Driver::SetLoginUser(User* user)
{
    loginUser_ = user;
}
void Driver::CreateUser()
{
    User** temp = new User*[userCount_+1];
    for (int i = 0; i < userCount_; i++)
    {
        temp[i] = allUsers_[i];
    }
    cout << "enter id:";
    string id, name;
    getline(cin, id);
    cout << "enter name:";
    getline(cin, name);
    temp[userCount_] = new User(id, name);
    userCount_++;
    delete[]allUsers_;
    allUsers_ = temp;
}

void Driver::CreatePage()
{
    Page** temp = new Page* [pageCount_ + 1];
    for (int i = 0; i < pageCount_; i++)
    {
        temp[i] = allPages_[i];
    }
    cout << "enter id:";
    string id, name,ownerid;
    getline(cin, id);
    cout << "enter title:";
    getline(cin, name);
    cout << "enter owner id:";
    getline(cin, ownerid);
    bool found = 0;
    for (int i = 0; i < userCount_&&!found; i++)
    {
        if (allUsers_[i]->GetId() == ownerid)
        {
            temp[pageCount_] = new Page(id,allUsers_[i],name);
            found = 1;
        }
    }
    delete[]allPages_;
    allPages_ = temp;
    pageCount_++;
    
}
Driver::~Driver()
{
    cout << "~driver() called" << endl;
    for (int i = 0; i < userCount_; i++)
    {
        delete allUsers_[i];
    }
    for (int i = 0; i < pageCount_; i++)
    {
        delete allPages_[i];
    }
    delete[]allUsers_;
    delete[]allPages_;
}
Driver::Driver()
{
    loginUser_ = nullptr;
    allUsers_ = nullptr;
    allPages_ = nullptr;
    userCount_ = 0;
    pageCount_ = 0;
    currentDate_ = Date(0,0,0);
}

