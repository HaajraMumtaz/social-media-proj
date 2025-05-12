#include <SFML/Graphics.hpp>
#include "Driver.h"
#include "Common.h"
#include "Page.h"
#include "PopUpForm.h"
#include "Post.h"
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
    int num2 = 0;
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\canva-elements\\2\\6.png"))
    {
        cout << "unable to load" << endl;
    }
    Font fontGeist;
    if (!fontGeist.loadFromFile("D:\\haajra\\oop-proj\\additional-files\\GeistMonoBold.ttf"))
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
    // Load font
    sf::Font font;
    if (!font.loadFromFile("D:\\haajra\\oop-proj\\additional-files\\Montserrat-Regular.ttf")) {
        std::cerr << "Font failed to load\n";
    }
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
   
    Text labelTL;
    labelTL.setFont(font);
    labelTL.setString("View Timeline");
    labelTL.setCharacterSize(26);
    labelTL.setFillColor(sf::Color(60, 60, 60)); 


    FloatRect textBounds = labelTL.getLocalBounds();
    labelTL.setOrigin(textBounds.width / 2, textBounds.height / 2);
    labelTL.setPosition(
        bbB1.left + bbB1.width / 2.5,
        bbB1.top + bbB1.height / 2 - 5
    );

    Text labelHome = labelTL;
    labelHome.setOrigin(textBounds.width / 2, textBounds.height / 2);
    labelHome.setPosition(
        bbB2.left + bbB2.width / 2.5,
        bbB2.top + bbB2.height / 2 - 5
    );
    labelHome.setString("View Home");

    Text labelDT = labelTL;
    labelDT.setOrigin(textBounds.width / 2, textBounds.height / 2);
    labelDT.setPosition(
        bbB3.left + bbB3.width / 2.5,
        bbB3.top + bbB3.height / 2 - 5
    );
    labelDT.setString("View Details");


    

    int num = 1;
    RectangleShape** todraw = new RectangleShape * [1];
    todraw[0] = new RectangleShape(Vector2f(width / 2, height / 5));
    todraw[0]->setPosition(Vector2f(but1.getPosition().x + bbB1.width + 10, 0));
   
    Sprite userButton;
    userButton.setTexture(userTexture);
    userButton.setScale(1, 1);
    userButton.setPosition(0, 0);

    userButton.setPosition(width - userButton.getLocalBounds().width-50, 0);
   
    
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
    PopupForm popup(fontGeist, Vector2f((width / 2) - 500 / 2, (height / 2) - 350 / 2));
  

    Text labelSUser = labelDT;
    labelSUser.setCharacterSize(24);
    textBounds = labelSUser.getLocalBounds();
    labelSUser.setPosition(
        searchUserB.getGlobalBounds().left + (searchUserB.getGlobalBounds().width - textBounds.width) / 2 - textBounds.left + 75,
        searchUserB.getGlobalBounds().top + 30  
    );
    labelSUser.setString("Search User");

    Text labelSPage = labelSUser;
    labelSPage.setPosition(
        searchPageB.getGlobalBounds().left + (searchPageB.getGlobalBounds().width - textBounds.width) / 2 - textBounds.left + 75,
        searchPageB.getGlobalBounds().top + 30
    );
    labelSPage.setString("Search Page");

    Text labelSPost = labelSUser;
    labelSPost.setPosition(
        searchPostB.getGlobalBounds().left + (searchPostB.getGlobalBounds().width - textBounds.width) / 2 - textBounds.left + 75,
        searchPostB.getGlobalBounds().top + 30
    );
    labelSPost.setString("Search Post");

    Text labelLoggedIn = labelSUser;
    labelLoggedIn.setString("Logged in user:\n" );
    labelLoggedIn.setFillColor(Color::Black);
    labelLoggedIn.setOrigin(labelLoggedIn.getLocalBounds().left + labelLoggedIn.getLocalBounds().width / 2.0f, labelLoggedIn.getLocalBounds().top + labelLoggedIn.getLocalBounds().height / 2.0f);
    labelLoggedIn.setPosition(userButton.getGlobalBounds().left + userButton.getGlobalBounds().width / 2.0f+20, userButton.getGlobalBounds().top + userButton.getGlobalBounds().height / 2.0f);


    Text labelAddUser = labelSPost;
    labelAddUser.setString("Add User");
    labelAddUser.setOrigin(labelAddUser.getLocalBounds().left + labelAddUser.getLocalBounds().width / 2.0f, labelAddUser.getLocalBounds().top + labelAddUser.getLocalBounds().height / 2.0f);
    labelAddUser.setPosition(bbAddUserB.left + bbAddUserB.width / 2.0f, bbAddUserB.top + bbAddUserB.height / 2.0f);

    Text labelAddPage = labelSPost;
    labelAddPage.setString("Add Page");
    labelAddPage.setOrigin(labelAddPage.getLocalBounds().left + labelAddPage.getLocalBounds().width / 2.0f, labelAddPage.getLocalBounds().top + labelAddPage.getLocalBounds().height / 2.0f);
    labelAddPage.setPosition(bbAddPageB.left + bbAddPageB.width / 2.0f, bbAddPageB.top + bbAddPageB.height / 2.0f);

    Text labelAddPost = labelSPost;
    labelAddPost.setString("Add Post");
    labelAddPost.setOrigin(labelAddPost.getLocalBounds().left + labelAddPost.getLocalBounds().width / 2.0f, labelAddPost.getLocalBounds().top + labelAddPost.getLocalBounds().height / 2.0f);
    labelAddPost.setPosition(bbAddPostB.left + bbAddPostB.width / 2.0f, bbAddPostB.top + bbAddPostB.height / 2.0f);

    Text labelAddFriend = labelSPost;
    labelAddFriend.setString("Add Friend");
    labelAddFriend.setOrigin(labelAddFriend.getLocalBounds().left + labelAddFriend.getLocalBounds().width / 2.0f, labelAddFriend.getLocalBounds().top + labelAddFriend.getLocalBounds().height / 2.0f);
    labelAddFriend.setPosition(bbAddFriendB.left + bbAddFriendB.width / 2.0f+10, bbAddFriendB.top + bbAddFriendB.height / 2.0f);

    Text labelLikePage = labelSPost;
    labelLikePage.setString("Like Page");
    labelLikePage.setOrigin(labelLikePage.getLocalBounds().left + labelLikePage.getLocalBounds().width / 2.0f, labelLikePage.getLocalBounds().top + labelLikePage.getLocalBounds().height / 2.0f);
    labelLikePage.setPosition(likePageB.getGlobalBounds().left + likePageB.getGlobalBounds().width / 2.0f+10, likePageB.getGlobalBounds().top + likePageB.getGlobalBounds().height / 2.0f);

    Text labelAddPagePost = labelSPost;
    labelAddPagePost.setString("Add Page Post");
    labelAddPagePost.setOrigin(labelAddPagePost.getLocalBounds().left + labelAddPagePost.getLocalBounds().width / 2.0f, labelAddPagePost.getLocalBounds().top + labelAddPagePost.getLocalBounds().height / 2.0f);
    labelAddPagePost.setPosition(addPagePostB.getGlobalBounds().left + addPagePostB.getGlobalBounds().width / 2.0f+20, addPagePostB.getGlobalBounds().top + addPagePostB.getGlobalBounds().height / 2.0f);


    DisplayLayout** layoutArr = new DisplayLayout*[1];
    layoutArr[0] = new DisplayLayout(fontGeist, todraw[0]->getPosition(), { 300, 150 });

    DisplayLayout layout(fontGeist, Vector2f(todraw[0]->getPosition().x+(0.25*todraw[0]->getLocalBounds().width),todraw[0]->getPosition().y+(1.5*todraw[0]->getLocalBounds().height)), {300, 150});
    RectangleShape** commentArr = new RectangleShape * [1];
    commentArr[0] = new RectangleShape();
    commentArr[0]->setFillColor(Color::White);
    commentArr[0]->setSize({300, 70});
    /*commentArr[0]->getPosition().x, commentArr[0]->getPosition().y + 20*/
    commentArr[0]->setPosition(layout.getPosition().x, layout.getPosition().y+layout.getSize().y);
  
    Text** textarr = new Text * [1];
    textarr[0] = new Text();
    textarr[0]->setPosition(todraw[0]->getPosition().x, todraw[0]->getPosition().y + (1.5 * todraw[0]->getLocalBounds().height) + 60);
  /*  textarr[0]->setPosition(0,0);*/
    textarr[0]->setFont(fontGeist);
    textarr[0]->setString("Users that have liked:");
    textarr[0]->setFillColor(Color::Black);
    layout.setData("u1", "temp", "0/0/0", "haajra");
    Text Sample1;
    Text Sample2;
    int screenState = 0;
    Post* postFound = nullptr;
    User* userFound = nullptr;
    Page* pageFound = nullptr;
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
    int state = -1;//0-timeline,1- homepage 2- details 3-userAdd 4-AddPage 5-changeuser 6-addpost 7-LikePage 8-addFriend 9-Add page post 10- Add post ID 11- view liked sub ID 12- search user ID 13-search page
    //allUsers_[1]->DisplayPosts();
    Vector2f windowPos = inputWindow.getPosition();
    RectangleShape feelingB(Vector2f((inputWindow.getSize().x-30)/2, (inputWindow.getSize().y - 30) / 2));
    Vector2f feeingLocal = feelingB.getSize();
    feelingB.setFillColor(Color::Red);
    feelingB.setPosition(inputWindow.getPosition().x+10, windowPos.y+10);
    int subState = -1;
    RectangleShape feelingB2 = feelingB;
    feelingB2.setPosition(windowPos.x + 20 + feeingLocal.x, feelingB.getPosition().y);

    RectangleShape feelingB3 = feelingB;
    feelingB3.setPosition(feelingB.getPosition().x, feelingB.getPosition().y+feeingLocal.y+10);
    string type;
    RectangleShape feelingB4 = feelingB;
    feelingB4.setPosition(feelingB2.getPosition().x, feelingB3.getPosition().y);
    string name, id, date;

    CircleShape commentB1;
    commentB1.setRadius(10);
    commentB1.setPosition(Vector2f(todraw[0]->getPosition().x+0.25 * todraw[0]->getLocalBounds().width, todraw[0]->getPosition().y+(1.5 * todraw[0]->getLocalBounds().height) +160));
    commentB1.setFillColor(Color::Red);
    CircleShape commentB2;
    commentB2 = commentB1;
    commentB2.setPosition(commentB1.getPosition().x + 40, commentB1.getPosition().y);
    CircleShape commentB3;
    commentB3 = commentB2;
    commentB3.setPosition(commentB2.getPosition().x + 40, commentB2.getPosition().y);
    
    Text heading;
    heading.setFont(fontGeist);
    heading.setFillColor(Color::Black);
    heading.setPosition(width / 2, height / 4);
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
                    for (int i = 1; i < num; i++)
                    {
                        delete layoutArr[i];
                    }
                    num = 1;
                    loginUser_->ViewTimeline(currentDate_, window, fontGeist, height, width, num, layoutArr);
                    state=0;
                    popupOpen = 0;
                    subButton1Clicked = 0;
                    subButton2Clicked = 0;
                    cout << "DELETED" << endl;

                }
                if (bbB2.contains(mousePos) && state!=1)
                {
                    
                    state = 1;
                    
                        for (int i = 1; i < num; i++)
                        {
                            delete layoutArr[i];
                        }
                        num = 1;
                    
                    cout<< "displaying your own posts:";
                    loginUser_->DisplayPosts(window,fontGeist,height,width,num,layoutArr);
                    popupOpen = 0;
                    subButton1Clicked = 0;
                }
                if (bbB3.contains(mousePos) && state!=2)
                {

                    
                    popupOpen = 1;
                    state = 2;
                    opt1 = opt2 = addPostB;
                    popupOpen = 1;
                    subButton1Clicked = subButton2Clicked = 0;
                    
                        for (int i = 1; i < num; i++)
                        {
                          
                            delete layoutArr[i];
                        }
                        num=1 ;
                    
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
                if (bbAddPageB.contains(mousePos) && state != 4)
                {
                    state = 4;
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
                if (likePageB.getGlobalBounds().contains(mousePos) && state != 7)
                {
                    state = 7;
                    popupOpen = 1;
                }
                if (bbAddFriendB.contains(mousePos) && state!=8)
                {
                    state = 8;
                    cout << "add friend via window" << endl;
                    popupOpen = 1;
                }
                
               
                if (addPagePostB.getGlobalBounds().contains(mousePos) && state != 9)
                {
                    state = 9;
                    popupOpen = 1;
                    
                }
                if (searchPostB.getGlobalBounds().contains(mousePos)&&state!=10)
                {
                    for (int k = 1; k < num2; k++)
                    {
                        cout <<"deleting:" << k << endl;
                        delete commentArr[k];
                        delete textarr[k];
                    }
                    num2 = 0;
                    state = 10;
                    popupOpen = 1;
                    subState = -1;
               /*     commentArr[0]->setPosition(layout.getPosition().x, layout.getPosition().y + layout.getSize().y);
                    textarr[0]->setPosition(commentArr[0]->getPosition().x, commentArr[0]->getPosition().y + 20);
                    */
                    subButton1Clicked = subButton2Clicked = subButton3Clicked = 0;
                    
                }
                if (searchUserB.getGlobalBounds().contains(mousePos) && state != 12)
                {
                    state = 12;
                    popupOpen = 1;
                    popup.setPrompt("Enter search user ID :");
                    subButton1Clicked = subButton2Clicked = subButton3Clicked = 0;
                    subState = -1;
                    for (int i = 1; i < num; i++)
                    {
                        delete layoutArr[i];
                    }
                    num = 1;
                    opt1 = opt2 = addPostB;
                    opt1.setPosition((inputWindow.getPosition().x + but1.getLocalBounds().width / 2) - 40, (inputWindow.getPosition().y + but1.getLocalBounds().height));
                    opt2.setPosition(opt1.getPosition().x, opt1.getPosition().y + 100);
                }
                if (searchPageB.getGlobalBounds().contains(mousePos) && state != 13)
                {
                    state = 13;
                    popupOpen = 1;
                    subState = -1;

                }
                
            }
           
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up)
            {
                state = -1;
                popupOpen = 0;
                popup.reset();
                subState = -1;
                subButton1Clicked = subButton2Clicked = subButton3Clicked = 0;
                   
            }
            if (state==3|| screenState == 0)
            {
                popup.handleEvent(event, 2);
            }
            if (state == 2)
            {
                cout << "here in event state 2" << endl;
                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
                {
                    if (opt1.getGlobalBounds().contains(mousePos))
                    {
                        
                        subButton1Clicked = 1;
                        subButton2Clicked = 0;
                        popupOpen = 0;
                        cout << "going in to get stuck" << endl;
                        loginUser_->DisplayDetails(window, fontGeist, height, width, num, layoutArr);
                    }
                    if (opt2.getGlobalBounds().contains(mousePos))
                    {
                        subButton1Clicked = 0;
                        subButton2Clicked = 1;
                        popupOpen = 0;
                        loginUser_->DisplayLikedPosts(window, fontGeist, height, width, num, layoutArr);

                    }

                }

            }
            if (state == 4)
            {
                popup.handleEvent(event, 3, "Enter Owner ID:", "Enter Title:");
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
                   
                    if ((opt1.getGlobalBounds().contains(mousePos)||subButton1Clicked)&&!subButton3Clicked)
                    {
                        
                        cout << "here in event state 6" << endl;
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
                        cout << "here:" << subState + 2 << endl;
                        if (subState==-1)
                        {
                            subButton1Clicked = subButton2Clicked = 0;
                            subButton3Clicked = 1;
                           
                            popupOpen = 1;
                            popup.handleEvent(event, 1);
                       }
                        if(subState==0)
                        {
                            if (feelingB.getGlobalBounds().contains(mousePos))
                                type = "feeling";
                            else if (feelingB2.getGlobalBounds().contains(mousePos))
                                type = "Thinking About";
                            else if (feelingB3.getGlobalBounds().contains(mousePos))
                                type = "Making";
                            else if (feelingB4.getGlobalBounds().contains(mousePos))
                                type = "Celebrating";

                         
                        }
                        if (subState == 1)
                        {
                            cout << "value create popup" << endl;
                            popup.setPrompt("Add Value:");
                            popupOpen = 1;
                            popup.handleEvent(event, 1);
                            cout << "value event" << endl;
                        }
                    }
                }
            }
           
            if (state==7)
            {
                popup.handleEvent(event, 1);
            }
            if (state == 9)
            {
                popup.handleEvent(event, 3,"Page ID:","Enter description:");
           }
            if (state == 10)
            {
                if (subState == -1)
                {
                    popup.setPrompt("Post ID to search:");
                    popup.handleEvent(event, 1);
                    subButton1Clicked = subButton2Clicked = subButton3Clicked;
                }
                else
                {
                    
                    
                    if (commentB1.getGlobalBounds().contains(mousePos) || subButton1Clicked)
                    {
                       
                        if (loginUser_->postAlreadyLiked(postFound))
                            postFound->AddLike(loginUser_);
                        else
                            cout << "already liked" << endl;
                        


                    }
                    else if (commentB2.getGlobalBounds().contains(mousePos) || subButton2Clicked)
                    {
                        subButton2Clicked = 1;
                        popup.setPrompt("Add comment:");
                        popup.handleEvent(event, 1);
                    }
                    else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && num2 > 0&& !commentB3.getGlobalBounds().contains(mousePos))
                    {/*
                        for (int i = 1; i < num2; i++)
                        {
                            delete textarr[i];
                            delete commentArr[i];
                        }*/
                        
                        subButton2Clicked = 0;
                        state = -1;

                        cout << "DELETED" << endl;
                    }
                }

               
                
            
                
            }
            if (commentB3.getGlobalBounds().contains(mousePos) && state == 10)//11th state
            {
                for (int i = 1; i < num2; i++)
                {
                    delete textarr[i];
                }
                num2 = 0;
             
                if (postFound)
                {
                    cout << "aithon" << endl;
                    postFound->DisplayLikedUsers(textarr, num2);
                }
                state = 11;
            }
            if (state == 12)
            {
                if (subState == -1)
                {
                    popup.handleEvent(event, 1);
                    cout << "state -1" << endl;

                }
                else
                {
                    cout << "state 0" << endl;
                    if (opt1.getGlobalBounds().contains(mousePos) && !subButton1Clicked)
                    {
                        subState = 1;
                        subButton1Clicked = 1;
                        subButton2Clicked = 0;
                        for (int i = 1; i < num; i++)
                        {
                            delete layoutArr[i];
                        }
                        num = 1;
                        userFound->DisplayFriends(window, fontGeist, height, width, num, layoutArr,0);
                       
                       
                    }
                    else if (opt2.getGlobalBounds().contains(mousePos) && !subButton2Clicked)
                    {
                        subState = 1;
                        subButton2Clicked = 1;
                        subButton1Clicked = 0;
                        for (int i = 1; i < num; i++)
                        {
                            delete layoutArr[i];

                        }
                        num = 1;
                        userFound->DisplayLikedPosts(window, fontGeist, height, width, num, layoutArr);
                        

                    }
                    else if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left&&!opt1.getGlobalBounds().contains(mousePos) && !opt2.getGlobalBounds().contains(mousePos) && (subButton1Clicked || subButton2Clicked))
                    {
                        cout << "cancelling" << endl;
                        state = -1;
                        popupOpen = 0;
                    }
                }
            }
            if (state == 13)
            {
                if (subState == -1)
                {
                    for (int i = 1; i < num; i++)
                    {
                        delete layoutArr[i];
                    }
                    num = 1;
                    popup.handleEvent(event, 1, "Search Page ID: ");
                }
                else if (subState == 0)
                {

                    pageFound->DisplayPosts(currentDate_, window, fontGeist, height, width, num, layoutArr);
                    cout << "likes:" << pageFound->GetNumLikes() << endl;
                    heading.setString(pageFound->GetId() + " " + pageFound->GetName() + " Number of likes:" + pageFound->GetNumLikes());
                    cout << "filling in state 13" << endl;
                    subState = 1;
                    
                }
               
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
                labelLoggedIn.setString("Logged in:\n" + popup.getID());
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
            window.draw(searchUserB);
            window.draw(searchPostB);
            window.draw(searchPageB);
            window.draw(labelTL);
            window.draw(labelHome);
            window.draw(labelDT);
            window.draw(labelSUser);
            window.draw(labelSPost);
            window.draw(labelSPage);
            window.draw(labelLoggedIn);
            window.draw(labelAddUser);
            window.draw(labelAddPage);
            window.draw(labelAddPost);
            window.draw(labelAddFriend);
            window.draw(labelLikePage);
            window.draw(labelAddPagePost);

            /*  window.draw(*todraw[0]);*/

            if (state==0||state==1)
            {
                for (int i = 1; i < num; i++)
                {
                    layoutArr[i]->draw(window);

                }
            }
            if (state == 2)
            {
                if (!subButton1Clicked && !subButton2Clicked)
                {
                    /*cout << "here in display" << endl;*/


                    window.draw(inputWindow);
                    window.draw(opt1);
                    window.draw(opt2);

                }


                else
                {
                    for (int i = 1; i < num; i++)
                    {
                        layoutArr[i]->draw(window);
                    }
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
            if (state == 4)
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
                            labelLoggedIn.setString("Logged in:\n" + popup.getID());
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
                    if(subState!=0)
                    popup.draw(window);
                    if (subState == 0)
                    {
                        window.draw(inputWindow);
                        window.draw(feelingB);
                        window.draw(feelingB2);
                        window.draw(feelingB3);
                        window.draw(feelingB4);
                    }
                    if (popup.isDone()||subState==0)
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
                        if (subButton3Clicked&&subState==-1)
                        {
                            cout << "adding activity" << endl;
                            loginUser_->AddActivity(popup.getID(), currentDate_.getDate());
                            cout << "added activity\n--------------" << endl;
                            subState = 0;
                            popup.reset();
                        }
                        else if (subButton3Clicked && subState==0&&type!="")
                        {
                            loginUser_->setType(type);
                            cout << "type set" << endl;
                            type = "";
                            subState = 1;
                            popupOpen = 1;
                        }
                        else if (subButton3Clicked && subState == 1)
                        {
                            cout << "valu draw" << endl;
                            loginUser_->setValue(popup.getID());
                            subState = -1;
                            subButton3Clicked = 0;
                            popupOpen = 0;
                            state = -1;
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
            if (state == 7)
            {
                popup.draw(window);
                if (popup.isDone())

                {
                    bool found = 0;
                    bool unique = 1;
                    for (int i = 0; i < pageCount_ && !found; i++)
                    {
                        if (allPages_[i]->GetId() == popup.getID())
                        {
                            found = 1;
                            unique = loginUser_->PageAlreadyLiked(allPages_[i]);
                            if (!unique)
                                cout << "already liked" << endl;
                            else
                                loginUser_->LikePage(allPages_[i]);
                        }
                    }
                    
                    state = -1;
                    popupOpen = 0;
                    popup.reset();
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
            if (state == 9)
            {
                popup.draw(window);
                if (popup.isDone())
                {
                    for (int i = 0; i < pageCount_; i++)
                    {
                        if (allPages_[i]->GetId() == popup.getTitle())
                        {
                            allPages_[i]->AddPost(currentDate_, popup.getID(), popup.getTitle(),currentDate_.getDate());
                        }
                    }
                    popup.reset();
                    state = -1;
                    popupOpen = 0;
                }
            }
            if (state == 10)
            {
                
                if (subState == -1)
                {
                    popup.draw(window);
                    if (popup.isDone())
                    {
                        bool found = 0;

                        int i = 0;
                        for (i = 0; i < userCount_ && !found; i++)
                        {
                            postFound = allUsers_[i]->searchPost(popup.getID(), found);
                        }
                        int j = 0;
                        for (j = 0; j < pageCount_ && !found; j++)
                        {
                            i = 0;
                            postFound=allPages_[i]->searchPost(popup.getID(), found);
                        }
                        if (found)
                        {
                           
                            if (i != 0)

                            {
                                layout.setData(postFound->GetId(), postFound->getDesc(), postFound->getDate(), allUsers_[i - 1]->GetName());
                                cout << "num bef" << num2 << endl;

                                postFound->getComments(commentArr, num2, textarr);
                                cout << "num after:" << num2 << endl;
                            }
                            else
                            {
                                layout.setData(postFound->GetId(), postFound->getDesc(), postFound->getDate(), allPages_[j - 1]->GetName());
                                cout << "num bef" << num2 << endl;

                                postFound->getComments(commentArr, num2, textarr);
                                cout << "num after:" << num2 << endl;
                            }

                            subState = 0;

                        }
                        else
                            state = -1;
                        popupOpen = 0;
                        popup.reset();
                        

                    }
                }
                else if (subState == 0)
                {
                    
                    layout.draw(window);
                    for (int k = 1; k <= num2; k++)
                    {
                       
                       
                        window.draw(*commentArr[k]);
                        window.draw(*textarr[k]);
                       
                    }
                    window.draw(commentB1);
                    window.draw(commentB2);
                    window.draw(commentB3);

                   
                    if (subButton2Clicked)
                    {
                        popup.draw(window);
                        if (popup.isDone())
                        {
                            postFound->AddComment(popup.getID(),loginUser_->GetId());
                            popupOpen = 0;
                            popup.reset();
                            subButton2Clicked = 0;
                        }
                    }
                 
                }
             
                
                
            }
            if (state == 11)
            {

              
                for (int i = 0; i <= num2; i++)
                {

                    window.draw(*textarr[i]);
                }


            }
            if (state == 12)
            {
                if (subState == -1)
                {
                    popup.draw(window);

                    if (popup.isDone() && subState == -1)
                    {
                        bool found = 0;
                        for (int i = 0; i < userCount_ && !found; i++)
                        {
                            if (allUsers_[i]->GetId() == popup.getID())
                            {
                                found = 1;
                                userFound = allUsers_[i];
                            }
                        }
                        if (found)
                            subState = 0;
                        else
                        {
                            state = -1;
                            popupOpen = 0;
                        }
                        popup.reset();
                        
                    }
                }
                else if (subState == 0)
                {
                    window.draw(inputWindow);
                    window.draw(opt1);
                    window.draw(opt2);
                }
                else if (subState == 1)
                {
                    cout << "displaying" << endl;
                    for (int i = 1; i < num; i++)
                    {
                        layoutArr[i]->draw(window);
                    }
                }

                
            }
            if (state == 13)
            {
                if (subState == -1)
                {
                    popup.draw(window);

                    if (popup.isDone())
                    {
                        bool found = 0;
                        for (int i = 0; i < pageCount_ && !found; i++)
                        {
                            if (allPages_[i]->GetId() == popup.getID())
                            {
                                found = 1;
                                pageFound = allPages_[i];
                                subState = 0;
                                
                            }
                        }
                        if (!found)
                            state = -1;
                        popupOpen = 0;
                        popup.reset();

                    }
                }
                else if (subState == 1)
                {
                    window.draw(heading);
                    for (int i = 1; i < num; i++)
                    {
                        layoutArr[i]->draw(window);
                    }
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

void Driver:: Deallocate(Text**&TextArr, RectangleShape**&RectArr, DisplayLayout**&LayoutArr,int&num2,int&num)
{
    for (int i = 0; i < num; i++)
    {
        delete LayoutArr[i];
    }
    num = 1;
    for (int i = 0; i <= num2; i++)
    {
        delete TextArr[i];
        delete RectArr[i];
    }
    num2 = 0;
    delete[]LayoutArr;
    delete[]TextArr;
    delete[]RectArr;

}