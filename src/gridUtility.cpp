#include "gridUtility.h"
namespace gridUtils {
	void drawGrid(std::vector<std::vector<gridItem>>& gridsArray, sf::RenderWindow& window) {
		int verticalOffset = 0;
		int horizontalOffset = 0;

		for (auto row : gridsArray) {
			horizontalOffset = 0;
			for (auto grid : row) {
				grid.setRectPosition(sf::Vector2f((horizontalOffset * consts::gridSize) + consts::borderThickness / 2, (verticalOffset * consts::gridSize) + consts::borderThickness / 2)); //This mess just prints each square in the correct place :')
				window.draw(grid.squareShape);
				horizontalOffset++;
			};
			verticalOffset++;
		}
	}
}