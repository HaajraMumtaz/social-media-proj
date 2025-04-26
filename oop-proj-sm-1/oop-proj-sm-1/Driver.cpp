#include <SFML/Graphics.hpp>
#include "Driver.h"
#include "Common.h"
using namespace sf;

void Driver::Run()
{
    int width = 800;
    int height = 600;
    RectangleShape rect1(Vector2f(100,100));
    Sprite but1;
    Texture buttonTexture;
    if (!buttonTexture.loadFromFile("D:\\haajra\\oop-proj\\UI inspo\\button.png"))
    {
        cout << "unable to load" << endl;
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
    while (window.isOpen()) {
   
        Event event;
        while (window.pollEvent(event)) {
            Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && boundingBoxB1.contains(mousePos))
            {
                cout << "ok works" << endl;
            }
        }

        window.clear(Color::Black);
        window.draw(but1);

        
        window.draw(but2);
        window.draw(but3);
        window.display();
    }


}

Driver::Driver()
{
    userCount_ = 0;
    pageCount_ = 0;
}
Driver::~Driver()
{
    userCount_ = 0;
    pageCount_ = 0;
}
int main() {
    // Create a window with 800x600 resolution and the title "SFML Test"
    
    Driver application;
    application.Run();
    return 0;
}