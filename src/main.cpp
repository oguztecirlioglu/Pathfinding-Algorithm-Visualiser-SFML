#include <stdio.h>
#include "SFML/Graphics.hpp"

//include the headers for own classes and files.
#include "mainMenu.h"
#include "utilityFunctions.h"


/* Checks if the pathfinding algorithm has found a solution to the problem. If yes, this will be set to false.
This keeps the drawing loop going. When isSolved == true, the drawing loop directly exits. */
bool isSolved = false; 

// Similar to isSolved, escapePressed is sent down to almost all functions by reference. If its value is set to true,
// it breaks out of the respective function, and returns the user back to the main menu. 
bool escapePressed = false;


int main() {
    // Create a window of size ROUNDED_X_SIZE, ROUNDED_Y_SIZE, and give it the title Visualise Pathfinding Algorithms!
	sf::RenderWindow window(sf::VideoMode(consts::ROUNDED_X_SIZE, consts::ROUNDED_Y_SIZE), "Visualise Pathfinding Algorithms!");
    mainMenu selectionMenu(window);

    while (window.isOpen())
    {
        // Draw the main menu, which clears, draws, and displays to the screen by itself.
        // notice how isSolved and escapePressed are passed down. 
        drawMenu(selectionMenu, window, isSolved, escapePressed);
    }

}