#include "mainMenu.h"

#include <iostream>


mainMenu::mainMenu(sf::RenderWindow& window) {
	stateWindow = &window;
	if (!font.loadFromFile("references/arial.ttf")) {
		// handle error
		std::cout << "error font" << std::endl;
	}
	// This vector of strings contains all the menu titles.
	std::vector<std::string> itemNames = { "Dijkstra's Algorithm", "Exit"};

	// Assigns each menu header to the array of sf::Text (which is a text object type, from SFML, used to draw text on screen)
	// The array of sf::Text is declared as a private variable with each object instantiated from mainMenu.
	assignMenuItems(itemNames);

	//initialise the state variables of this object.
	numberOfMenuItems = itemNames.size();
	selectedItemIndex = 0;
};


mainMenu::~mainMenu() {
	// Destructor, no need to do anything here for this class.
};


/*The draw function draws each item from the array of sf::Text called menuItems (mentioned earlier on lines 15) to the screen, using the window objects draw method.*/
void mainMenu::draw()
{
	for (int i = 0; i < numberOfMenuItems; i++) {
		stateWindow->draw(menuItems[i]);
	}
}

/* Assigns each string in the vector of strings itemNames to a position in the menuItems array.
Also does the necessary steps to make each header look pretty, or at the right place.*/
void mainMenu::assignMenuItems(std::vector<std::string> itemNames) {

	for (int i = 0; i < numberOfMenuItems; ++i) {
		menuItems[i].setCharacterSize(55);
		menuItems[i].setFont(font);
		menuItems[i].setFillColor(sf::Color::Blue);
		menuItems[i].setString(itemNames[i]);
		menuItems[i].setPosition(sf::Vector2f(consts::ROUNDED_X_SIZE / 10, (i + 1) * (consts::ROUNDED_Y_SIZE / (itemNames.size() + 3))));
	}
	menuItems[0].setFillColor(sf::Color::White);
}

/* This function is called everytime the keyboard, up arrow is pressed. It simply checks if there is space left to go a higher header, and if so, goes there.*/
void mainMenu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex--;
		menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

/* This function is called everytime the keyboard, down arrow is pressed. It simply checks if there is space left to go to a lower header, and if so, goes there.*/
void mainMenu::MoveDown() {
	if (selectedItemIndex + 1 < NUMBER_OF_MENU_ITEMS) {
		menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex++;
		menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

/* Returns the index of the selected menu title (In a menu with 2 titles, like dijkstra and exit, a return value of 1 would give exit. */
int mainMenu::getPressedItem() {
	return selectedItemIndex;
}

/* This function is not a part of the mainMenu class. It simply does the following:
	1. Initially draw the menu headers, and start with the top item selected.
	2. Listens for keyboard events (press return, or up or down arrow keys)
	3. Either enter the selected pathfinding algorithms visualisation, or exit.
	4. If escape is pressed and we break out of the algorithms visualisation, set escapePressed to false, rinse and repeat.
	5. If exit is selected, close the window and exit the program.
*/
void drawMenu(mainMenu& selectionMenu, sf::RenderWindow& window, bool& isSolved, bool& escapePressed) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyReleased:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				selectionMenu.MoveUp();
				break;

			case sf::Keyboard::Down:
				selectionMenu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (selectionMenu.getPressedItem()) {
				case 0:
					dijkstra(window, isSolved, escapePressed);
					escapePressed = false;
					break;

				case 1:
					window.close();
					break;
				}
				break;
			}
		}
	}

	window.clear();

	selectionMenu.draw();

	window.display();
}