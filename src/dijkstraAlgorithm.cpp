#include "dijkstraAlgorithm.h"
#include <chrono>
#include <thread>

void dijkstraAlgorithm(std::vector<std::vector<gridItem>>& gridItems, sf::RenderWindow& window, sf::Vector2i& source, sf::Vector2i& target, bool& escapePressed){
	// Create a queue to place each gridItem on to. First put the source, and then any neighbors of source, and then neighbors of neighbors etc..
	// Using queue as a data structure ensures we traverse everything in the right order (First in First out)
	std::queue<gridItem*> gridStack;
	gridStack.push(utilityFuncs::getGridAt(source, gridItems));

	// Get the target grids coordinates so that we can traverse from here to home back.
	gridItem* targetGrid = utilityFuncs::getGridAt(target, gridItems);

	// This is the "Dijkstra Loop", where every square is visited and its distance set. 
	while (!gridStack.empty() && !escapePressed) {
		utilityFuncs::grabEvents(window, escapePressed);
		window.clear();
		gridUtils::drawGrid(gridItems, window);
		window.display();

		gridItem* current = gridStack.front();
		gridStack.pop();

		gridItem* up;
		gridItem* down;
		gridItem* left;
		gridItem* right;

		if (current->checkIfTarget()) break;
		if(!current->checkIfHome()) current->squareShape.setFillColor(sf::Color(125,125,125));

		int currentX = current->getLocation().x;
		int currentY = current->getLocation().y;

		// Check to see if a gridItem above the current one exists (to avoid undefined behaviour etc.)
		if (currentX - 1 >= 0) {
			 up = utilityFuncs::getGridAt(sf::Vector2i{ currentX - 1, currentY }, gridItems);
			 if (!(up->checkIfTraversed()) && !(up->checkIfWall())) {
				 up->setTraversed();
				 up->setDistance(current->getDistance() + 1);
				 gridStack.push(up);
			 }
		}
		if (currentX + 1 < consts::verticalGridCount) {
			down = utilityFuncs::getGridAt(sf::Vector2i{ currentX + 1, currentY }, gridItems);
			if (!(down->checkIfTraversed()) && !(down->checkIfWall())) {
				down->setTraversed();
				down->setDistance(current->getDistance() + 1);
				gridStack.push(down);
			}

		}
		if (currentY - 1 >= 0) {
			left = utilityFuncs::getGridAt(sf::Vector2i{ currentX, currentY - 1 }, gridItems);
			if (!(left->checkIfTraversed()) && !(left->checkIfWall())) {
				left->setTraversed();
				left->setDistance(current->getDistance() + 1);
				gridStack.push(left);
			}

		}
		if (currentY + 1 < consts::horizontalGridCount) {
			right = utilityFuncs::getGridAt(sf::Vector2i{ currentX, currentY + 1 }, gridItems);
			if (!(right->checkIfTraversed()) && !(right->checkIfWall())) {
				 right->setTraversed();
				 right->setDistance(current->getDistance() + 1);
				 gridStack.push(right);
			 }

		}
	}
	// Dijkstra loop finished, so now we can draw the shortest path.
	
	// To draw the path, the targetGrid, which is constantly changed throughout this loop, must not be at home.
	while (!targetGrid->checkIfHome() && !escapePressed) {
		// find the minimum neighbor of the target grid. make target grid that minimum neighbor.
		gridItem *up = nullptr, *down = nullptr, *left = nullptr, *right = nullptr;
		int upDistance = INT_MAX, downDistance = INT_MAX, leftDistance = INT_MAX, rightDistance = INT_MAX;
		int minDist = 0;

		int currentX = targetGrid->getLocation().x;
		int currentY = targetGrid->getLocation().y;
		
		targetGrid->squareShape.setFillColor(sf::Color::Blue);

		if (currentX - 1 >= 0) {
			up = utilityFuncs::getGridAt(sf::Vector2i{ currentX - 1, currentY }, gridItems);
			upDistance = up->getDistance();
		}
		if (currentX + 1 < consts::verticalGridCount) {
			down = utilityFuncs::getGridAt(sf::Vector2i{ currentX + 1, currentY }, gridItems);
			downDistance = down->getDistance();
		}
		if (currentY - 1 >= 0) {
			left = utilityFuncs::getGridAt(sf::Vector2i{ currentX, currentY - 1 }, gridItems);
			leftDistance = left->getDistance();
		}
		if (currentY + 1 < consts::horizontalGridCount) {
			right = utilityFuncs::getGridAt(sf::Vector2i{ currentX, currentY + 1 }, gridItems);
			rightDistance = right->getDistance();
		}

		minDist = std::min({ upDistance, downDistance, leftDistance, rightDistance, INT_MAX - 1 });
		if (minDist == upDistance) targetGrid = up;
		else if (minDist == downDistance) targetGrid = down;
		else if (minDist == leftDistance) targetGrid = left;
		else if (minDist == rightDistance) targetGrid = right;

		utilityFuncs::grabEvents(window, escapePressed);
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
		window.clear();
		gridUtils::drawGrid(gridItems, window);
		window.display();
	}

}