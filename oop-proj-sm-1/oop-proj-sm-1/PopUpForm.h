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
    PopupForm(const Font& font, Vector2f position);
    void handleEvent(const Event& event,int num, const string& prompt2="Enter name:",const string&prompt3="Enter Date (DD/MM/YYYY):");
    void draw(RenderWindow& window);
    bool isDone();
    string getID();
    string getTitle();
    string getDate();
    void reset();
};