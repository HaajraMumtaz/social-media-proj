#include "PopupForm.h"
using namespace std;
using namespace sf;
PopupForm::PopupForm(const Font& font, Vector2f position) {

    box.setSize(Vector2f(500, 350));
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

void PopupForm::handleEvent(const Event& event, int num, const string& prompt2,const string&prompt3)
{

    if (stage == 3) return;

    if (event.type == Event::TextEntered) {
        if (event.text.unicode == '\b') {
            if (!currentInput.empty())
                currentInput.pop_back();
        }
        else if (event.text.unicode == '\r') {
            if (stage == 0)
            {
                if (num>1)
                {
                    promptText.setString(prompt2);
                    stage = 1;
                }
                else
                {
                    title = "";
                    stage = 3;
                }
                id = currentInput;
                currentInput.clear();
            }

            else if (stage == 1) {
                {
                    if (num > 2)
                    {
                        stage = 2;
                        promptText.setString(prompt3);
                     
                    }
                    else
                    {
                        stage = 3;

                    }
                    title = currentInput;
                    currentInput.clear();
                }
            }
            else if (stage == 2)
            {
                date = currentInput;
                currentInput.clear();
                stage = 3;
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
    return stage == 3;
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
string PopupForm::getDate()
{
    return date;
}



    DisplayLayout::DisplayLayout(const Font& font, Vector2f position, Vector2f size)
    {
  
        

        box_.setSize(size);
        box_.setPosition(position);
        box_.setFillColor(Color(220, 220, 220));
        box_.setOutlineColor(Color::Black);
        box_.setOutlineThickness(2);

        descText_.setFont(font);
        dateText_.setFont(font);
        idText_.setFont(font);
        ownerText_.setFont(font);

        descText_.setCharacterSize(18);
        dateText_.setCharacterSize(18);
        idText_.setCharacterSize(18);
        ownerText_.setCharacterSize(18);

        descText_.setFillColor(Color::Black);
        dateText_.setFillColor(Color::Black);
        idText_.setFillColor(Color::Black);
        ownerText_.setFillColor(Color::Black);
    
    }

    void DisplayLayout::setBase(const Font& font, Vector2f position, Vector2f size)
    {
        box_.setSize(size);
        box_.setPosition(position);
        box_.setFillColor(Color(220, 220, 220));
        box_.setOutlineColor(Color::Black);
        box_.setOutlineThickness(2);

        descText_.setFont(font);
        dateText_.setFont(font);
        idText_.setFont(font);
        ownerText_.setFont(font);
        
        descText_.setCharacterSize(18);
        dateText_.setCharacterSize(18);
        idText_.setCharacterSize(18);
        ownerText_.setCharacterSize(18);

        descText_.setFillColor(Color::Black);
        dateText_.setFillColor(Color::Black);
        idText_.setFillColor(Color::Black);
        ownerText_.setFillColor(Color::Black);

    }
    void DisplayLayout::setData(const string& id, const string& desc, const string& date, const string& owner)
    {
        id_ = id;
        description_ = desc;
        date_ = date;
        ownerName_ = owner;

        idText_.setString("ID: " + id_);
        descText_.setString("Title: " + description_);
        dateText_.setString("Date: " + date_);
        ownerText_.setString("Owner: " + ownerName_);

        // Adjust text positions relative to box_
        Vector2f pos = box_.getPosition();
        idText_.setPosition(pos.x + 10, pos.y + 10);
        descText_.setPosition(pos.x + 10, pos.y + 40);
        dateText_.setPosition(pos.x + 10, pos.y + 70);
        ownerText_.setPosition(pos.x + 10, pos.y + 100);
    }

    void DisplayLayout::draw(RenderWindow& window)
    {
        window.draw(box_);
        window.draw(idText_);
        window.draw(ownerText_);
      
            window.draw(box_);
            window.draw(idText_);
            window.draw(descText_);
            window.draw(dateText_);
            window.draw(ownerText_);
        
        
    }


    DisplayMemory::DisplayMemory(const sf::Font& font, sf::Vector2f position, sf::Vector2f size)
        : DisplayLayout(font, position + Vector2f(0, 50), size) // Shift base post downward
    {
        bannerText_.setFont(font);
        bannerText_.setCharacterSize(20);
        bannerText_.setFillColor(sf::Color::Yellow);
        bannerText_.setPosition(position.x,position.y); // top

        commentText_.setFont(font);
        commentText_.setCharacterSize(24);
        commentText_.setFillColor(sf::Color::Cyan);
        commentText_.setPosition(position + sf::Vector2f(0, 20)); // Banner goes exactly where the original position was
    }

    void DisplayMemory::setMemory(const std::string& originalDate, const std::string& comment, const std::string& id,const std::string& desc, const std::string& date, const std::string& owner)
    {
        bannerText_.setString("Reshared a post from " + originalDate+ comment);
        commentText_.setString(comment);
        DisplayLayout::setData(id, desc, date, owner);  // Call parent setter to fill normal post data
    }

    void DisplayMemory::draw(sf::RenderWindow& window)
    {
        window.draw(bannerText_);
        window.draw(commentText_);
        DisplayLayout::draw(window);  // Draw the actual post
    }