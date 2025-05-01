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

    int stage = 0; // 0 = ID, 1 = Title, 2 = Done
public:
    PopupForm(const Font& font,Vector2f position);
    void handleEvent(const Event& event, const string& prompt2);
    void draw(RenderWindow& window);
    bool isDone();
    string getID();
    string getTitle();
    void reset();
};