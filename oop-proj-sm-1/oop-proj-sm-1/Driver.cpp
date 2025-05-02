#include <SFML/Graphics.hpp>
#include "Driver.h"
#include "Common.h"
#include "Page.h"
#include "PopUpForm.h"
using namespace sf;

void Driver::Run()
{


    int width = 1280;
    int height = 720;
    // Initializing variables & objects
    sf::Color myColor(185, 207, 208);
    RenderWindow window(VideoMode(width, height), "Enter ID and Name");

    RectangleShape inputWindow(Vector2f(450, 300));
    RectangleShape rect1(Vector2f(100, 100));

    inputWindow.setPosition(200, 200);
    inputWindow.setFillColor(Color::Cyan);
    Sprite but1;
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2-n.png"))
    {
        cout << "unable to load" << endl;
    }
    Font font;
    if (!font.loadFromFile("D:\\haajra\\oop-proj\\additional-files\\GeistMonoBold.ttf"))
    {
        cout << "cant load" << endl;
    }
    Texture userTexture;
    if (!userTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\4 (2).png"))
    {
        cout << "unable to load" << endl;
    }
    Texture addTexture;
    if (!addTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\3 (2).png"))
    {
        cout << "unable to load" << endl;
    }
    float scaleFactor = min(width / buttonTexture.getSize().x, height / buttonTexture.getSize().y);


    but1.setTexture(buttonTexture);
    but1.setScale(0.2, 0.2);

    but1.setPosition(10, window.getSize().y / 3);
    Sprite but3 = but1;
    but3.setPosition(but1.getPosition().x, but1.getPosition().y + (height / 3));
    Sprite but2 = but1;
    but2.setPosition((but1.getPosition().x + but3.getPosition().x) / 2, (but1.getPosition().y + but3.getPosition().y) / 2);
    FloatRect boundingBoxB1 = but1.getGlobalBounds();
    FloatRect boundingBoxB2 = but2.getGlobalBounds();
    FloatRect boundingBoxB3 = but3.getGlobalBounds();
    int num = 1;
    RectangleShape** todraw = new RectangleShape * [1];
    todraw[0] = new RectangleShape(Vector2f(width / 2, height / 5));
    todraw[0]->setPosition(Vector2f(but1.getPosition().x + boundingBoxB1.width + 10, 0));
    todraw[0]->setOutlineColor(Color::White);
    todraw[0]->setOutlineThickness(10);
    Text** todrawtext = new Text * [1];
    todrawtext[0] = new Text;
    todrawtext[0]->setFillColor(Color::Black);
    todrawtext[0]->setPosition(todraw[0]->getPosition());
    todrawtext[0]->setCharacterSize(28);

    Sprite userButton;
    userButton.setTexture(userTexture);
    userButton.setScale(1, 1);
    userButton.setPosition(0, 0);
    userButton.setPosition(width - boundingBoxB3.width, 10);
    Text loginUserId;
    loginUserId.setFont(font);
    loginUserId.setFillColor(Color::Black);
    loginUserId.setCharacterSize(22);
    loginUserId.setPosition(userButton.getPosition().x + 7, (loginUserId.getPosition().y + 18));

    Sprite addUserB;
    addUserB.setTexture(addTexture);
    addUserB.setScale(1, 1);
    addUserB.setPosition(width - userButton.getLocalBounds().width - 150, 10);
    FloatRect boundingBoxAddUserB = addUserB.getGlobalBounds();

    Sprite addPostB = addUserB;
    addPostB.setPosition(width / 2, 9 * height / 10);

    Sprite addFriendB;
    addFriendB = addPostB;
    addFriendB.setPosition(width / 3, 9 * height / 10);

    FloatRect boundingBoxAddPostB = addPostB.getGlobalBounds();
    FloatRect boundingBoxUserB = userButton.getGlobalBounds();
    FloatRect boundingBoxAddFriendB = addFriendB.getGlobalBounds();
    PopupForm popup(font, Vector2f((width / 2) - 500 / 2, (height / 2) - 350 / 2));
    Text Sample1;
    Text Sample2;
    int screenState = 0;
    ////////////////////////////////////////////////////////////////////////////////////////////////
    //CreateUser();
    //CreateUser();
    //CreatePage();
    //allUsers_[0]->DisplayDetails();
    //allUsers_[0]->AddFriend(allUsers_[1]);
    //allUsers_[0]->LikePage(allPages_, pageCount_);
    //allUsers_[1]->AddPost(currentDate_);
    //allUsers_[1]->AddPost(currentDate_);
    //allPages_[0]->AddPost();
    bool UserInputPopup = 0;
    bool changeUserPopup = 0;
    bool addPostPopup = 0;
    bool addFriendPopup = 0;
    //allUsers_[1]->DisplayPosts();
    bool on = 0;
    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                if (boundingBoxB1.contains(mousePos) && !on)
                {
                    cout << "ok works" << endl;
                    loginUser_->ViewTimeline(currentDate_, window, font, height, width, num, todraw, todrawtext);
                    on = 1;
                }


                if (boundingBoxAddUserB.contains(mousePos) && !UserInputPopup)
                {
                    cout << "add user via window" << endl;
                    UserInputPopup = 1;

                }
                if (boundingBoxUserB.contains(mousePos))
                {
                    on = 0;
                    changeUserPopup = 1;

                    for (int i = 1; i < num; i++)
                    {
                        delete todraw[i];
                        delete todrawtext[i];
                    }
                    num = 1;

                }
                if (boundingBoxAddPostB.contains(mousePos)&&!addPostPopup)
                {
                    addPostPopup = 1;
                    cout << "add post via window:" << endl;
                }
                if (boundingBoxAddFriendB.contains(mousePos) && !addFriendPopup)
                {
                    addFriendPopup = 1;
                    cout << "add friend via window" << endl;
                }
            }
            if (UserInputPopup || screenState == 0)
            {
                popup.handleEvent(event, 2);
            }
            if (changeUserPopup || addFriendPopup)
            {
                popup.handleEvent(event, 1);
            }
            if (addPostPopup)
            {
                popup.handleEvent(event, 3, "Enter Description of post:");
            }
           
        }

        window.clear(myColor);
        if (screenState == 0)
        {
            popup.draw(window);
            if (popup.isDone())
            {
                screenState = 1;
                CreateUser(popup.getID(), popup.getTitle());
                SetLoginUser(allUsers_[0]);
                loginUserId.setString("Logged in: " + popup.getID());
                popup.reset();
            }


        }
        else if (screenState == 1)
        {
            window.draw(addUserB);
            window.draw(but1);
            window.draw(but2);
            window.draw(but3);
            window.draw(userButton);
            window.draw(addPostB);
            window.draw(addFriendB);
            window.draw(loginUserId);
          
            /*  window.draw(*todraw[0]);*/

            if (on)
            {
                for (int i = 1; i < num; i++)
                {
                    window.draw(*todraw[i]);
                    window.draw(*todrawtext[i]);

                }
            }
            if (UserInputPopup)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    CreateUser(popup.getID(), popup.getTitle());
                    UserInputPopup = 0;
                    popup.reset();
                }

            }
            if (changeUserPopup)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    bool found = 0;
                    for (int i = 0; i < userCount_ && !found; i++)
                    {
                        if (allUsers_[i]->GetId() == popup.getID())
                        {
                            found = 1;
                            SetLoginUser(allUsers_[i]);
                            loginUserId.setString("Logged in: " + popup.getID());
                        }

                    }
                    popup.reset();
                    changeUserPopup = 0;
                }
            }
            if (addPostPopup)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    loginUser_->AddPost(currentDate_,popup.getID(),popup.getTitle(),popup.getDate());
                    popup.reset();
                    addPostPopup = 0;
                }
             
            }
            if (addFriendPopup)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    bool found = 0;
                    for (int i = 0; i < userCount_&&!found; i++)
                    {
                        if (allUsers_[i]->GetId() == popup.getID())
                        {
                            loginUser_->AddFriend(allUsers_[i]);
                            allUsers_[i]->AddFriend(loginUser_);
                            found = 1;
                        }
                    }
                    popup.reset();
                    addFriendPopup = 0;
                }
            }


        }
        window.display();
    }

}

void Driver::SetLoginUser(User* user)
{
    cout << "login user set to:" << user->GetId() << endl;
    loginUser_ = user;
}
void Driver::CreateUser()
{
    User** temp = new User * [userCount_ + 1];
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
void Driver::CreateUser(string id, string name)
{
    User** temp = new User * [userCount_ + 1];
    for (int i = 0; i < userCount_; i++)
    {
        temp[i] = allUsers_[i];
    }

    temp[userCount_] = new User(id, name);
    userCount_++;
    delete[]allUsers_;
    allUsers_ = temp;
}

void Driver::CreatePage()
{
    Page** temp = new Page * [pageCount_ + 1];
    for (int i = 0; i < pageCount_; i++)
    {
        temp[i] = allPages_[i];
    }
    cout << "enter id:";
    string id, name, ownerid;
    getline(cin, id);
    cout << "enter title:";
    getline(cin, name);
    cout << "enter owner id:";
    getline(cin, ownerid);
    bool found = 0;
    for (int i = 0; i < userCount_ && !found; i++)
    {
        if (allUsers_[i]->GetId() == ownerid)
        {
            temp[pageCount_] = new Page(id, allUsers_[i], name);
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
    currentDate_ = Date(0, 0, 0);
}

User* Driver::GetLoginUser()
{
    return loginUser_;
}