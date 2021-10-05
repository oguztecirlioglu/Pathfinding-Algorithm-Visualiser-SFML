#pragma once
#include "SFML/Graphics.hpp"
#include "gridItem.h"
#include <iostream>
#include <queue>
#include "utilityFunctions.h"
#include <algorithm>

void dijkstraAlgorithm(std::vector<std::vector<gridItem>>& gridItems, sf::RenderWindow& window, sf::Vector2i& source, sf::Vector2i& target, bool& escapePressed);