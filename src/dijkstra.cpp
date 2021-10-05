#include "dijkstra.h"
#include <iostream>

/*	Inputs: an SFML RenderWindow object: window, a boolean: isSolved, a boolean: escapePressed 
	Outputs: None.
	Functionality: This is a big function, and basically carries out Dijkstra's algorithm. To summarise quickly, it looks at the source node to begin with.
	Then, the algorithm peeks, if possible (no walls or out of bounds) at the grids above, below, to the left, and right of it. It sets the distances of these grids
	to the increment of its own distance. For the source grid, its own distance would be 0, and all of its neighbors distances would be 1.
	The methodology is this: put source grid in queue, pop it from queue, set all of its neighbors distance to 1, and then pop them all on the queue.
	Then, one by one, pop them from the queue, check their neighbors, give them distance = distance + 1, and pop the new neighbors on the queue.
	If we hit the target node, just break, because by this point we must have enough information to find the shortest path.
*/

void dijkstra(sf::RenderWindow& window, bool& isSolved, bool& escapePressed) {
	// Initialise the vector of <gridItems> which is defined in gridItem.h and implemented in gridItem.cpp.
	// The grid is drawn by the information contained by each object in this 2d vector array.
	std::vector<std::vector<gridItem>> gridsArray(consts::verticalGridCount, std::vector<gridItem>(consts::horizontalGridCount));
	sf::Vector2i sourceCoords, targetCoords;
	for (int row = 0; row < consts::verticalGridCount; row++) {
		for (int col = 0; col < consts::horizontalGridCount; col++) {
			gridsArray.at(row).at(col).setLocation(sf::Vector2i{ row, col });
		}
	}
	// Check which click the user is on. Eg: step 0-> set Origin grid, step 1-> set target grid, step 2-> set wall grids.
	int setupStep = 0;

	
	// Dijkstra event loop
	while (!(escapePressed || isSolved)) {

		/* There are 3 different window listen events.One listens to a mouse click, the other to a mouse drag, and the last
		only listens if the escape button has been pressed */
		switch (setupStep) {
		case 0:
		case 1:
			utilityFuncs::grabMouseClickEvents(window, escapePressed, setupStep, gridsArray, sourceCoords, targetCoords);
			break;
		case 2:
			utilityFuncs::grabMouseDragEvents(window, escapePressed, setupStep, gridsArray);
			break;
		case 3:
			utilityFuncs::grabEvents(window, escapePressed);
			dijkstraAlgorithm(gridsArray, window, sourceCoords,targetCoords, escapePressed);
			setupStep++;
			break;
		default:
			utilityFuncs::grabEvents(window, escapePressed);
			break;
		}

		// Clear the window and listen for the window close event, basically do basic maintenance.
		window.clear();
		gridUtils::drawGrid(gridsArray, window);
		window.display();

	}
}
