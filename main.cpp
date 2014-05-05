#include <iostream>
#include <SFML/Graphics.hpp>

#include "Sprite.h"

int main (int argc, char *argv[])
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML window");

    Sprite s(10);

	// Start the game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();

            if (Event.Type == sf::Event::KeyPressed)
            {
                 if (Event.Key.Code == sf::Key::Right)
                    s.move(Sprite::RIGHT);
                 else if (Event.Key.Code == sf::Key::Down)
                    s.move(Sprite::DOWN);
                 else if (Event.Key.Code == sf::Key::Left)
                    s.move(Sprite::LEFT);
                 else if (Event.Key.Code == sf::Key::Up)
                    s.move(Sprite::UP);
            }
        }

        // Clear screen
        App.Clear();

        // Draw the sprite
        App.Draw(s.get_sprite());

        // Update the window
        App.Display();
    }

    return EXIT_SUCCESS;
}
