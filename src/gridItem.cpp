#include "gridItem.h"

#pragma once

gridItem::gridItem() {
	this->squareShape.setSize(sf::Vector2f(consts::adjustedGridSize, consts::adjustedGridSize));
	this->squareShape.setFillColor(sf::Color::Black);
	this->squareShape.setOutlineColor(sf::Color::White);
	this->squareShape.setOutlineThickness(10.f);
}

gridItem::~gridItem() {
	
}

void gridItem::setLocation(sf::Vector2i location) {
	this->location = location;
}

void gridItem::setHome() {
	this->isHome = true;
	this->isTraversed = true;
	this->distance = 0;
}

void gridItem::setWall() {
	this->isWall = true;
}

void gridItem::setTraversed() {
	this->isTraversed = true;
}

void gridItem::setIntoPath() {
	this->isPath = true;
}

void gridItem::setTarget() {
	this->isTarget = true;
}

bool gridItem::checkIfWall() {
	return this->isWall;
}

bool gridItem::checkIfHome() {
	return this->isHome;
}

bool gridItem::checkIfTraversed() {
	return this->isTraversed;
}

bool gridItem::checkIfPath() {
	return this->isPath;
}

bool gridItem::checkIfTarget() {
	return this->isTarget;
}

sf::Vector2i gridItem::getLocation() {
	return this->location;
}

void gridItem::setRectPosition(sf::Vector2f pos) {
	this->squareShape.setPosition(pos);
}

void gridItem::setDistance(int distance) {
	this->distance = distance;
}

int gridItem::getDistance() {
	return this->distance;
}

