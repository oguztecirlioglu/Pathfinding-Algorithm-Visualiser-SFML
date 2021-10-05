#pragma once
#include "SFML/Graphics.hpp"
namespace consts {
	const int X_SIZE = sf::VideoMode::getDesktopMode().width / 150; // Desktop Width divided by 150, so that the rounded x size (which is rounded to hundreds) can be obtained.
	const int ROUNDED_X_SIZE = X_SIZE * 100;

	const int Y_SIZE = sf::VideoMode::getDesktopMode().height/ 150; // Desktop Width divided by 150, so that the rounded x size (which is rounded to hundreds) can be obtained.
	const int ROUNDED_Y_SIZE = Y_SIZE * 100;

	// Grid item sizes
	const float gridSize = 100; // Proposed size of a full grid including its border.
	const float borderThickness = 10.f; // Thickness of the border.
	const float adjustedGridSize = gridSize - borderThickness; // Adjusted grid size. SFML adds the border on top of the original size so I had to account for this and substract it.

	//Grid counts
	// Self explanatory, how many grids lie horizontally and vertically from left to right and top to bottom respectively. 

	const int horizontalGridCount = consts::ROUNDED_X_SIZE / consts::gridSize;
	const int verticalGridCount = consts::ROUNDED_Y_SIZE / consts::gridSize;
}