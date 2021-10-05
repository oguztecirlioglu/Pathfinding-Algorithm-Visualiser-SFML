#pragma once

#include "SFML/Graphics.hpp"
#include "CONSTANTS.h"
#include "gridItem.h"
#include "gridUtility.h"

namespace utilityFuncs{
	void grabEvents(sf::RenderWindow& window, bool& escapePressed);
	void grabMouseClickEvents(sf::RenderWindow& window, bool& escapePressed, int& step, std::vector<std::vector<gridItem>>& gridsArray, sf::Vector2i& homeCoords, sf::Vector2i& targetCoords);
	void grabMouseDragEvents(sf::RenderWindow& window, bool& escapePressed, int& step, std::vector<std::vector<gridItem>>& gridsArray);
	gridItem* getGridAt(sf::Vector2i location, std::vector<std::vector<gridItem>>& gridsArray);

	sf::Vector2i mouseCoordinate(sf::Vector2i mousePos);
}