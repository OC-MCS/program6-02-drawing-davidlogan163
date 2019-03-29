#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"
#include <iostream>
#include <iomanip>
#include <string>

void die(string end);

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *settingsMgr;
public:
	// Constructor
	SettingsUI(SettingsMgr *mgr)
	{
		settingsMgr = mgr;
	}
	// Displays buttons and text
	void draw(RenderWindow& win) {
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\Ebrima.ttf")) {
			die("Error opening file!");
		}

		// Dssplaying circle colors to choose
		Text Colors;
		Colors.setString("Select Color:");
		Colors.setFont(font);
		Colors.setPosition(15, 50);
		win.draw(Colors);

		CircleShape redButton(25), blueButton(25), greenButton(25);
		CircleShape circle(25);

		// Red button circle settings
		redButton.setPosition(75, 100);
		redButton.setOutlineThickness(3);
		redButton.setFillColor(Color::Transparent);
		redButton.setOutlineColor(Color::Red);

		// Blue button circle settings
		blueButton.setPosition(75, 250);
		blueButton.setFillColor(Color::Transparent);
		blueButton.setOutlineThickness(3);
		blueButton.setOutlineColor(Color::Blue);

		// Green button Circle Settings
		greenButton.setPosition(75, 175);
		greenButton.setOutlineThickness(3);
		greenButton.setFillColor(Color::Transparent);
		greenButton.setOutlineColor(Color::Green);

		Color C = settingsMgr->getCurColor();
		if (C == Color::Red) {
			redButton.setFillColor(Color::Red);
		}
		else if (C == Color::Blue) {
			blueButton.setFillColor(Color::Blue);
		}
		else if (C == Color::Green) {
			greenButton.setFillColor(Color::Green);
		}

		RectangleShape square(Vector2f(50, 50));
		// Circle option settings
		circle.setOutlineThickness(3);
		circle.setPosition(75, 400);
		circle.setFillColor(Color::Transparent);
		circle.setOutlineColor(Color::White);

		// Square settings
		square.setOutlineThickness(3);
		square.setPosition(75, 475);
		square.setFillColor(Color::Transparent);
		square.setOutlineColor(Color::White);

		ShapeEnum S = settingsMgr->getCurShape();
		if (S == CIRCLE) {
			circle.setFillColor(Color::White);
		}
		else if (S == SQUARE) {
			square.setFillColor(Color::White);
		}

		win.draw(circle);
		win.draw(square);
		win.draw(redButton);
		win.draw(blueButton);
		win.draw(greenButton);

		// Displaying shapes to choose
		Text Shapes;
		Shapes.setString("Select Shape:");
		Shapes.setPosition(5, 350);
		Shapes.setFont(font);
		win.draw(Shapes);
	}

	// Checks if the mouse has selected any options
	void handleMouseUp(Vector2f mouse)
	{
		if (mouse.x > 75 && mouse.x < 125){
			if (mouse.y > 100 && mouse.y < 150){
				settingsMgr->setColor(Color::Red);
			}
			else if (mouse.y > 250 && mouse.y < 300){
				settingsMgr->setColor(Color::Blue);
			}
			else if (mouse.y > 175 && mouse.y < 225){
				settingsMgr->setColor(Color::Green);
			}
			else if (mouse.y > 475 && mouse.y < 525) {
				settingsMgr->setShape(SQUARE);
			}
			else if (mouse.y > 400 && mouse.y < 450){
				settingsMgr->setShape(CIRCLE);
			}
		}
	}
};

void die(string end)
{
	cout << end << endl;
	exit(-1);
}