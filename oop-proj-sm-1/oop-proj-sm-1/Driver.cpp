#include <SFML/Graphics.hpp>
#include "Driver.h"


void Driver::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // Main loop that keeps the window open until it's closed
    while (window.isOpen()) {
        // Event loop to handle events like closing the window
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the screen with a black color
        window.clear(sf::Color::Black);

        // Display the content of the window (shows the black screen)
        window.display();
    }


}

int main() {
    // Create a window with 800x600 resolution and the title "SFML Test"
    
    Driver application;
    application.run();
    return 0;
}