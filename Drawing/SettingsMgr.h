#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
using namespace std;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color color;
	ShapeEnum shape;
public:
	// Constructor
	SettingsMgr(Color startingColor, ShapeEnum startingShape){
		color = startingColor;
		shape = startingShape;
	}

	// Reads the color and shape settings from the file
	void readFile(fstream& inFile) {
		unsigned int colorSetting;
		inFile.read(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		inFile.read(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
		color = Color(colorSetting);
	}

	// Writes the color and shape settings to the file
	void writeFile(fstream& outFile) {
		unsigned int colorSetting = color.toInteger();
		outFile.write(reinterpret_cast<char*>(&colorSetting), sizeof(unsigned int));
		outFile.write(reinterpret_cast<char*>(&shape), sizeof(ShapeEnum));
	}

	// Returns the current color
	Color getCurColor(){
		return color;
	}

	// Returns the current shape
	ShapeEnum getCurShape(){
		return shape;
	}

	// Sets current color to the input value
	void setColor(Color C){
		color = C;
	}

	// Sets current shape to the input value
	void setShape(ShapeEnum S){
		shape = S;
	}


};
