/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>

// Our global constants to remove magic numbers
 float BrushRadius = 64.f;
 sf::Color BrushColor = sf::Color::Green;
 
// Main, our applicaiton entry function
int main()
{
	// Create the window for the game
	// All rendering happens here
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	// Create our "brush" (as a circle shape), with a radius of BrushRadius pixels
    sf::CircleShape shape(BrushRadius);
	
	// Set the color of our "brush"
    shape.setFillColor(BrushColor);

	// This is our game loop!
	// All input, logic, and rendering should be handled here
    while (window.isOpen())
    {
		// Check for events from the window
		// E.g., is the window being closed?
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Space key creates a screenshot
            if (event.key.code == sf::Keyboard::Space)
            {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
                {
                    std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                sf::Color BrushColor = sf::Color::Red;
             
                shape.setFillColor(BrushColor);// Change color to red
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
            {
                sf::Color BrushColor = sf::Color::Green;
                shape.setFillColor(BrushColor);// change color to green
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
            {
                sf::Color BrushColor = sf::Color::Blue;
                shape.setFillColor(BrushColor);// change color to blue
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                BrushRadius = BrushRadius+4;
                shape.setRadius(BrushRadius);// radiu plus 4
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                BrushRadius = BrushRadius-4;
                shape.setRadius(BrushRadius);// radiu minurs 4
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
            {
                shape.setOutlineThickness(10);
                shape.setOutlineColor(sf::Color(250, 150, 100));// add a outline 
            }
        }

		// This clears the window at the beginning of every frame
		// If we comment this out, it is a very simple way to create a paintbrush effect since the window is never cleared
        //window.clear();
		
		// Set the position of our "brush" to the mouse position
		// Don't forget to offset by the "brush" radius to center it on the mouse position
        shape.setPosition(sf::Mouse::getPosition(window).x - BrushRadius, sf::Mouse::getPosition(window).y - BrushRadius);
		
		// Draw our "brush" to the window buffer
        window.draw(shape);
		
		// Display the window buffer for this frame
        window.display();
    }

	// The game has exited normally so send a normal exit status integer back
    return 0;
}