#pragma once

#include "SFML/Graphics.hpp" 
#include "CONSTANTS.h"
#include "dijkstra.h"

const int NUMBER_OF_MENU_ITEMS = 2;


class mainMenu
{
public:
	mainMenu(sf::RenderWindow& window);
	~mainMenu();

	void draw();
	void MoveUp();
	void MoveDown();
	int getPressedItem();

private:
	sf::RenderWindow* stateWindow;
	int numberOfMenuItems = NUMBER_OF_MENU_ITEMS;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menuItems[NUMBER_OF_MENU_ITEMS];
	void assignMenuItems(std::vector<std::string> itemNames);

};

void drawMenu(mainMenu& sortMenu, sf::RenderWindow& window, bool& isSolved, bool& escapePressed);