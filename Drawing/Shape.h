#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>

using namespace std;

struct Shapes {
	ShapeEnum shape;
	float x, y;
	unsigned int color;
};

class DrawingShape
{
public:
	virtual void draw(RenderWindow& win) = 0;
	virtual Shapes getFile() = 0;
};

class Square : public DrawingShape {
private:
	RectangleShape rect;
public:
	// Constructor
	Square(Vector2f pos, Color color) {
		rect.setPosition(pos);
		rect.setFillColor(color);
		rect.setSize(Vector2f(20, 20));
	}

	// Draws the rectangles in the canvas
	void draw(RenderWindow& win) {
		win.draw(rect);
	}

	// Returns a shape to the file
	Shapes getFile() {
		return { SQUARE, rect.getPosition().x, rect.getPosition().y, rect.getFillColor().toInteger() };
	}
};

class Circle : public DrawingShape{
private:
	CircleShape circ;
public:
	// Constructor
	Circle(Vector2f pos, Color color){
		circ.setPosition(pos);
		circ.setFillColor(color);
		circ.setRadius(10);
	}

	// Draws the circles in the canvas
	void draw(RenderWindow& win){
		win.draw(circ);
	}

	// Returns a shape to the file
	Shapes getFile(){
		return { CIRCLE, circ.getPosition().x, circ.getPosition().y, circ.getFillColor().toInteger() };
	}
};

