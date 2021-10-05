#pragma once
#include "SFML/Graphics.hpp"
#include "CONSTANTS.h"

/* Objective: To create a class that can contain anything possible needed to describe a grid cell in the pathfinding visualiser tool. */
class gridItem {
private:
	bool isWall = false;
	bool isTraversed = false;
	bool isPath = false;
	bool isTarget = false;
	bool isHome = false;
	sf::Vector2i location;
public:
	int distance = INT_MAX;

	sf::RectangleShape squareShape;
	gridItem();
	~gridItem();
	// Setters
	void setWall();
	void setTraversed();
	void setIntoPath();
	void setTarget();
	void setHome();
	void setDistance(int distance);
	void setLocation(sf::Vector2i location);

	// Getters
	bool checkIfTarget();
	bool checkIfHome();
	bool checkIfWall();
	bool checkIfTraversed();
	bool checkIfPath();
	int getDistance();
	sf::Vector2i getLocation();

	// Set position of the sf::RectangeShape 
	void setRectPosition(sf::Vector2f pos);
};