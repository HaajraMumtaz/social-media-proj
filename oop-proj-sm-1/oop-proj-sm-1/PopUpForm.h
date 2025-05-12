#pragma once

#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;
class PopupForm {
private:
    RectangleShape box;
    Text promptText;
    Text inputDisplay;

    string currentInput;
    string id;
    string title;
    string date;
    int stage = 0; // 0 = ID, 1 = Title, 2 = Date, 3=Done
   
public:
    PopupForm(const sf::Font& font, sf::Vector2f position);
    void handleEvent(const Event& event,int num, const string& prompt2="Enter name:",const string&prompt3="Enter Date (DD/MM/YYYY):");
    void draw(RenderWindow& window);
    bool isDone();
    string getID();
    string getTitle();
    string getDate();
    inline void setPrompt(string toSet)
    {
        promptText.setString(toSet);

    }
    void reset();
};

class Displaylayout
{
private:
    RectangleShape box_;
    String description_;
    String Date_;
    String Id_;
    String OwnerName_;
    Text descText_;
    Text dateText_;
    Text idText_;
    Text ownerText_;
public:

};

class DisplayLayout
{
private:
    RectangleShape box_;
    string description_;
    string date_;
    string id_;
    string ownerName_;

    Text descText_;
    Text dateText_;
    Text idText_;
    Text ownerText_;

public:
    DisplayLayout(const sf::Font&font, sf::Vector2f position, sf::Vector2f size);
    void setData(const string& id, const string& desc, const string& date, const string& owner, string idPrompt = "ID: ", string descPrompt = "Title: ", string datePrompt = "Date: ", string ownerPrompt = "Owner: ");
    virtual void draw(RenderWindow& window);
    inline Vector2f getPosition()
    {
        return box_.getPosition();
    }
    inline Vector2f getSize()
    {
        return box_.getSize();
    }
    void setBase(const Font& font, Vector2f position, Vector2f size);
    virtual inline string getDate()
    {
        return date_;
    }
    virtual inline string getId()
    {
        return id_;
    }
    inline void setUser(string user)
    {
        ownerName_ = user;
    }
  
};

class DisplayMemory : public DisplayLayout
{
private:
    sf::Text bannerText_;   
    sf::Text commentText_; 

public:
    DisplayMemory(const sf::Font& font, sf::Vector2f position, sf::Vector2f size);

    // New setter to customize the banner
    void setMemory(const std::string& originalDate, const std::string& comment, const std::string& id,const std::string& desc, const std::string& date, const std::string& owner);

    // Override draw to draw the banner first, then the post
    void draw(sf::RenderWindow& window);

};
