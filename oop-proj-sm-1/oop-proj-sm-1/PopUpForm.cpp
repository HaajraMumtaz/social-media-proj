#include "PopupForm.h"
using namespace std;
using namespace sf;
PopupForm::PopupForm(const Font& font, Vector2f position) {
    box.setSize(Vector2f( 500, 350 ));
    box.setFillColor(sf::Color(50, 50, 50, 230));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);
    box.setPosition(position);

    promptText.setFont(font);
    promptText.setCharacterSize(40);
    promptText.setFillColor(sf::Color::Cyan);
    promptText.setPosition(position.x + 20, position.y + 20);
    promptText.setString("Enter ID:");

    inputDisplay.setFont(font);
    inputDisplay.setCharacterSize(20);
    inputDisplay.setFillColor(sf::Color::Cyan);
    inputDisplay.setPosition(position.x + 20, position.y + 70);
}

void PopupForm::handleEvent(const Event&event,const string& prompt2,bool showOne)
{
    
    if (stage == 2) return;

    if (event.type == Event::TextEntered) {
        if (event.text.unicode == '\b') {
            if (!currentInput.empty())
                currentInput.pop_back();
        }
        else if (event.text.unicode == '\r') {
            if (stage == 0) 
            {
                if (!showOne)
                {
                    promptText.setString(prompt2);
                    stage = 1;
                }
                if (showOne)
                {
                    title = "";
                    stage = 2;
                }
                id = currentInput;
                currentInput.clear();
            }
          
            else if (stage == 1) {
                title = currentInput;
                currentInput.clear();
                stage = 2;
            }
        }
        else if (event.text.unicode < 128) {
            currentInput += static_cast<char>(event.text.unicode);
        }

        inputDisplay.setString(currentInput);
    }
}

void PopupForm::draw(RenderWindow& window) {
    window.draw(box);
    window.draw(promptText);
    window.draw(inputDisplay);
}

bool PopupForm::isDone() {
    return stage == 2;
}

string PopupForm::getID() {
    return id;
}

string PopupForm::getTitle() {
    return title;
}

void PopupForm::reset()
{
        id.clear();
        title.clear();
        currentInput.clear();
        stage = 0;
        promptText.setString("Enter ID:");
        inputDisplay.setString("");
    
}