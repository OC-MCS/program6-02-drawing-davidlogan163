#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeMgr.h"
#include <iostream>
#include <iomanip>
using namespace std;

class DrawingUI
{
private:
	Vector2f pos;
public:
	// Constructor
	DrawingUI(Vector2f P){
		pos = P;
	}

	// Determines if the mouse is in the canvas or not
	bool isMouseInCanvas(Vector2f mousePos) {
		return mousePos.x > pos.x && mousePos.x < pos.x + 570 && mousePos.y > pos.y && mousePos.y < pos.y + 485;
	}
	// Draws the canvas
	void draw(RenderWindow& win, ShapeMgr *mgr){
		RectangleShape box;
		box.setPosition(pos);
		box.setOutlineColor(Color::White);
		box.setOutlineThickness(1);
		box.setSize(Vector2f(575, 500));
		win.draw(box);

		vector<DrawingShape*> shapes = mgr->getShapes();
		for (int i = 0; i < shapes.size(); i++){
			shapes[i]->draw(win);
		}
	}
};