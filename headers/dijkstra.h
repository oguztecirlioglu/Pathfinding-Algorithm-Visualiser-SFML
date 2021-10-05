#pragma once
#include "SFML/Graphics.hpp"
#include "CONSTANTS.h"
#include "utilityFunctions.h"
#include "gridItem.h"
#include "gridUtility.h"
#include "dijkstraAlgorithm.h"

void dijkstra(sf::RenderWindow& window, bool& isSolved, bool& escapePressed);

