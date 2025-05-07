#include <SFML/Graphics.hpp>
#include "Driver.h"
#include "Common.h"
#include "Page.h"
#include "PopUpForm.h"
using namespace sf;
using namespace std;
void Driver::Run()
{


    int width = 1280;
    int height = 720;
    // Initializing variables & objects
    sf::Color myColor(185, 207, 208);
    RenderWindow window(VideoMode(width, height), "Enter ID and Name");

    RectangleShape inputWindow(Vector2f(500, 350));
    RectangleShape rect1(Vector2f(100, 100));

    inputWindow.setPosition(Vector2f(((width / 2) - 500 / 2), ((height / 2) - 350 / 2)+20));
    inputWindow.setFillColor(Color::Cyan);
    Sprite but1;
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2\\6.png"))
    {
        cout << "unable to load" << endl;
    }
    Font font;
    if (!font.loadFromFile("D:\\haajra\\oop-proj\\additional-files\\GeistMonoBold.ttf"))
    {
        cout << "cant load" << endl;
    }
    Texture userTexture;
    if (!userTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2\\2.png"))
    {
        cout << "unable to load" << endl;
    }
    Texture addTexture;
    if (!addTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2\\4.png"))
    {
        cout << "unable to load" << endl;
    }
    Texture searchTexture;
    if (!searchTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2\\3.png"))
    {
        cout << "unable to load" << endl;
    }
    float scaleFactor = min(width / buttonTexture.getSize().x, height / buttonTexture.getSize().y);


    but1.setTexture(buttonTexture);
    but1.setScale(0.9, 0.9);

    but1.setPosition(10, window.getSize().y / 3);
    Sprite but3 = but1;
    but3.setPosition(but1.getPosition().x, but1.getPosition().y + (height / 3));
    Sprite but2 = but1;
    but2.setPosition((but1.getPosition().x + but3.getPosition().x) / 2, (but1.getPosition().y + but3.getPosition().y) / 2);
    FloatRect bbB1 = but1.getGlobalBounds();
    FloatRect bbB2 = but2.getGlobalBounds();
    FloatRect bbB3 = but3.getGlobalBounds();
   
    int num = 1;
    RectangleShape** todraw = new RectangleShape * [1];
    todraw[0] = new RectangleShape(Vector2f(width / 2, height / 5));
    todraw[0]->setPosition(Vector2f(but1.getPosition().x + bbB1.width + 10, 0));
   
    Sprite userButton;
    userButton.setTexture(userTexture);
    userButton.setScale(1, 1);
    userButton.setPosition(0, 0);

    userButton.setPosition(width - userButton.getLocalBounds().width-50, 0);
    Text loginUserId;
    loginUserId.setFont(font);
    loginUserId.setFillColor(Color::Black);
    loginUserId.setCharacterSize(22);
    loginUserId.setPosition(userButton.getPosition().x, (userButton.getPosition().y + 50));
    
    Sprite addUserB;
    addUserB.setTexture(addTexture);
    addUserB.setScale(1, 1);
    addUserB.setPosition(width - userButton.getLocalBounds().width-addUserB.getLocalBounds().width-70, 30);
    FloatRect bbAddUserB = addUserB.getGlobalBounds();

    Sprite addPostB = addUserB;
    int buttonGapPos = (width - addPostB.getLocalBounds().width * 4) / 4;
    addPostB.setPosition(buttonGapPos, 9 * height / 10);
    int downButtonWidth = addPostB.getLocalBounds().width;
    Sprite addFriendB;
    addFriendB = addPostB;
    addFriendB.setPosition(addPostB.getPosition().x+downButtonWidth+buttonGapPos, 9 * height / 10);

    Sprite likePageB;
    likePageB = addFriendB;
    likePageB.setPosition(addFriendB.getPosition().x +downButtonWidth+ buttonGapPos, 9 * height / 10);

    Sprite addPagePostB;
    addPagePostB= addFriendB;
    addPagePostB.setPosition(likePageB.getPosition().x + downButtonWidth + buttonGapPos, 9 * height / 10);

    Sprite searchUserB;
    searchUserB.setTexture(searchTexture);
    searchUserB.setScale(0.9, 0.9);
    searchUserB.setPosition(width - searchUserB.getLocalBounds().width - 30, but1.getPosition().y);

    Sprite searchPageB;
    searchPageB = searchUserB;
    searchPageB.setPosition(searchUserB.getPosition().x, but2.getPosition().y);

    Sprite searchPostB;
    searchPostB = searchUserB;
    searchPostB.setPosition(searchUserB.getPosition().x, but3.getPosition().y);

    Sprite addPageB;
    addPageB = addUserB;
    addPageB.setPosition(addUserB.getPosition().x, addUserB.getPosition().y + 80);

    Sprite opt1;
    Sprite opt2;
    Sprite opt3;

   
    FloatRect bbAddPostB = addPostB.getGlobalBounds();
    FloatRect bbUserB = userButton.getGlobalBounds();
    FloatRect bbAddFriendB = addFriendB.getGlobalBounds();
    FloatRect bbAddPageB = addPageB.getGlobalBounds();
    PopupForm popup(font, Vector2f((width / 2) - 500 / 2, (height / 2) - 350 / 2));
    DisplayLayout layout(font,todraw[0]->getPosition(), {300, 150});
    layout.setData("u1", "temp", "0/0/0", "haajra");
    DisplayLayout** layoutArr = new DisplayLayout*[1];
    layoutArr[0] = new DisplayLayout(font, todraw[0]->getPosition(), { 300, 150 });
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
    bool popupOpen = 0,completed=0;
    bool subButton1Clicked=0,subButton2Clicked = 0,subButton3Clicked=0;
    bool defaultstate = 0;
    int state = -1;//0-timeline,1- homepage 2- details 3-userAdd 4-AddPage 5-changeuser 6-addpost 7-LikePage 8-addFriend
    //allUsers_[1]->DisplayPosts();

    string name, id, date;
    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left&&!popupOpen)
            {
                if (bbB1.contains(mousePos) && state!=0)
                {
                    cout << "ok works" << endl;
                    if (num != 1)
                    {
                        for (int i = 1; i < num; i++)
                        {
                            delete layoutArr;
                        }
                        num = 1;
                    }
                    loginUser_->ViewTimeline(currentDate_, window, font, height, width, num, layoutArr);
                    state=0;
                    popupOpen = 0;
                    subButton1Clicked = 0;
                }
                if (bbB2.contains(mousePos) && state!=1)
                {
                    
                    state = 1;
                    if (num != 1)
                    {
                        for (int i = 1; i < num; i++)
                        {
                            delete layoutArr[i];
                        }
                        num = 1;
                    }
                    cout<< "displaying your own posts:";
                    loginUser_->DisplayPosts(window,font,height,width,num,layoutArr);
                    popupOpen = 0;
                    subButton1Clicked = 0;
                }
                if (bbB3.contains(mousePos) && state!=2)
                {

                    
                    popupOpen = 1;
                    state = 2;
                    opt1 = opt2 = addPostB;
                    popupOpen = 1;

                    if (num != 1)
                    {
                        for (int i = 1; i < num; i++)
                        {
                          
                            delete layoutArr[i];
                        }
                        num = 1;
                    }
                    opt1.setPosition((inputWindow.getPosition().x + but1.getLocalBounds().width/2)-40, (inputWindow.getPosition().y + but1.getLocalBounds().height));
                    opt2.setPosition(opt1.getPosition().x, opt1.getPosition().y + 100);

                    cout << "atleast here" << endl;
                }
                if (bbAddUserB.contains(mousePos) && state!=3)
                {
                    cout << "add user via window" << endl;
                    state=3;
                    popupOpen = 1;

                }
                if (bbUserB.contains(mousePos)&&state!=5)
                {
                    
                    state = 5;
                    for (int i = 1; i < num; i++)
                    {
                      
                        delete layoutArr[i];
                    }
                    num = 1;
                    popupOpen = 1;

                }
                if (bbAddPostB.contains(mousePos)&&state!=6)
                {
                    state=6;
                    opt1 = opt2 = opt3=addPostB;
                    opt1.setPosition((inputWindow.getPosition().x + but1.getLocalBounds().width / 2) - 40, (inputWindow.getPosition().y + but1.getLocalBounds().height)-50);
                    opt2.setPosition(opt1.getPosition().x, opt1.getPosition().y + 80);
                    opt3.setPosition(opt2.getPosition().x, opt1.getPosition().y + 160);
                    cout << "add post via window:" << endl;
                    popupOpen = 1;
                }
                if (bbAddFriendB.contains(mousePos) && state!=8)
                {
                    state = 8;
                    cout << "add friend via window" << endl;
                    popupOpen = 1;
                }
                if (bbAddPageB.contains(mousePos) && state!=4)
                {
                    state = 4;
                    popupOpen = 1;
                }
                if (likePageB.getGlobalBounds().contains(mousePos) && state!=7)
                {
                    state = 7;
                    popupOpen = 1;
                }
            }
            if (state==3|| screenState == 0)
            {
                popup.handleEvent(event, 2);
            }
            if (state==5 || state==8)
            {
                popup.handleEvent(event, 1);
            }
            if (state==6)
            {
               /* popup.handleEvent(event, 3, "Enter Description of post:");
                cout << "here in post event" << endl;
                popup.handleEvent(event, 3, "Enter title");*/
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left||subButton1Clicked||subButton2Clicked||subButton3Clicked)
                {
                   
                    if (opt1.getGlobalBounds().contains(mousePos)||subButton1Clicked)
                    {
                        
                        cout << "here in event" << endl;
                        subButton1Clicked = 1;
                        popupOpen = 0;
                        popup.handleEvent(event, 3);
                       
                    }
                    if (opt2.getGlobalBounds().contains(mousePos)||subButton2Clicked)
                    {
                        subButton1Clicked = 0;
                        subButton2Clicked = 1;
                        
                        popupOpen = 0;
                        popup.handleEvent(event, 3,"Enter original post ID:","Enter Description:");
                       
                    }
                    if (opt3.getGlobalBounds().contains(mousePos)||subButton3Clicked)
                    {
                        subButton1Clicked = subButton2Clicked=0;
                        subButton3Clicked = 1;
                       
                        popupOpen = 0;
                        

                    }
                }
            }
            if (state==4)
            {
                popup.handleEvent(event, 3, "Enter Owner ID:", "Enter Title:");
            }
            if (state==2)
            {
                cout << "here in event" << endl;
                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                    {
                        if (opt1.getGlobalBounds().contains(mousePos))
                        {
                            defaultstate = 0;
                            subButton1Clicked = 1;
                            popupOpen = 0;
                            cout << "going in to get stuck" << endl;
                            loginUser_->DisplayDetails(window, font, height, width, num,layoutArr);
                        }
                        if(opt2.getGlobalBounds().contains(mousePos))
                        {
                            subButton1Clicked = 0;
                            defaultstate = 1;
                            popupOpen = 0;
                            state = -1;
                            
                        }
                    }
   
            }
            if (state==7)
            {
                popup.handleEvent(event, 1);
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
                popupOpen = 0;
                popup.reset();
            }


        }
        else if (screenState == 1)
        {
            
            window.draw(addUserB);
            window.draw(addPageB);
            window.draw(but1);
            window.draw(but2);
            window.draw(but3);
            window.draw(userButton);
            window.draw(addPostB);
            window.draw(addFriendB);
            window.draw(likePageB);
            window.draw(addPagePostB);
            window.draw(loginUserId);
            window.draw(searchUserB);
            window.draw(searchPostB);
            window.draw(searchPageB);
            
            if (state==2)
            {    
                if (!subButton1Clicked)
                {
                    /*cout << "here in display" << endl;*/
                    if (!defaultstate)
                    {
                        window.draw(inputWindow);
                        window.draw(opt1);
                        window.draw(opt2);
                    }
                    else
                    {
                        cout << "in else" << endl;
                        state = -1;
                        popupOpen = 0;
                        
                    }
                }
                

                if (subButton1Clicked)
                {
                    for (int i = 1; i < num; i++)
                    {
                        layoutArr[i]->draw(window);
                    }
                }
                
            }
          
            /*  window.draw(*todraw[0]);*/

            if (state==0||state==1)
            {
                for (int i = 1; i < num; i++)
                {
                    layoutArr[i]->draw(window);

                }
            }
            if (state==3)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    CreateUser(popup.getID(), popup.getTitle());
                    state = -1;
                    popupOpen = 0;
                    popup.reset();
                }

            }
            if (state==5)
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
                    state = -1;
                    popupOpen = 0;
                }
            }
            if (state==6)
            {
               
                if (!subButton1Clicked && !subButton2Clicked && !subButton3Clicked)
                {
                    window.draw(inputWindow);
                    window.draw(opt1);
                    window.draw(opt2);
                    window.draw(opt3);
                }
                else
                {
                    popup.draw(window);

                    if (popup.isDone())
                    {
                        if (subButton1Clicked)
                        {
                            subButton1Clicked = 0;
                            defaultstate = 1;
                            state = -1;
                            popupOpen = 0;
                            loginUser_->AddPost(currentDate_, popup.getID(), popup.getTitle(), popup.getDate());
                            popup.reset();
                        }
                        if (subButton2Clicked)
                        {
                            subButton2Clicked = 0;
                            defaultstate = 1;
                            popupOpen = 0;
                            cout << popup.getID() << popup.getTitle() << popup.getDate() << endl;
                            loginUser_->AddMemory(currentDate_, popup.getID(), popup.getTitle(), popup.getDate());//this id, old ID, desc
                            popup.reset();
                        }
                    }

                 /*   if (completed && subButton1Clicked)
                    {

                        loginUser_->AddPost(currentDate_, id, name, date);
                        completed = 0;
                        subButton1Clicked = 0;
                        state = -1;
                        cout << "simple post added:" << id << endl;
                    }
                    if (completed && subButton2Clicked)
                    {

                        loginUser_->AddPost(currentDate_, id, name, date);
                        completed = 0;
                        subButton1Clicked = 0;
                        state = -1;
                        cout << "simple post added:" << id << endl;
                    }*/
                }
             
            }
            
            if (state==8)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    bool found = 0;
                    for (int i = 0; i < userCount_&&!found&&popup.getID()!=loginUser_->GetId(); i++)
                    {
                        
                        if (allUsers_[i]->GetId() == popup.getID())
                        {
                            loginUser_->AddFriend(allUsers_[i]);
                            allUsers_[i]->AddFriend(loginUser_);
                            found = 1;
                        }
                    }
                    popup.reset();
                    state = -1;
                    popupOpen = 0;
                }
            }
            if (state==4)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    bool found = 0;
                    for (int i = 0; i < userCount_ && !found; i++)
                    {
                        if (allUsers_[i]->GetId() == popup.getTitle())
                        {
                            Page** temp = new Page * [pageCount_ + 1];
                            for (int i = 0; i < pageCount_; i++)
                            {
                                temp[i] = allPages_[i];
                            }
                            delete[]allPages_;
                            allPages_ = temp;
                            found = 1;
                            allPages_[pageCount_++] = new Page(popup.getID(), allUsers_[i], popup.getDate());
                            cout << allPages_[pageCount_ - 1]->GetId() << endl;
                            
                        }

                    }
                    popupOpen = 0;
                    state = -1;
             
                    popup.reset();
                }
             
            }
            if (state==7)
            {
                popup.draw(window);
                if (popup.isDone())

                {
                    bool found =0;
                    for (int i = 0; i <pageCount_&& !found; i++)
                    {
                        if (allPages_[i]->GetId() == popup.getID())
                        {
                            found = 1;
                            loginUser_->LikePage(allPages_[i]);
                        }
                    }
                    state = -1;
                    popupOpen = 0;
                    popup.reset();
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