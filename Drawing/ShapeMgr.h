#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iomanip>
using namespace std;

class ShapeMgr
{
private:
	vector<DrawingShape*> shape;
public:
	// Constructor
	ShapeMgr(){
	}

	void addShape(Vector2f pos, ShapeEnum pickShape, Color color){
		switch (pickShape){
			case CIRCLE:
				shape.push_back(new Circle(pos, color));
				break;
			case SQUARE:
				shape.push_back(new Square(pos, color));
				break;
		}
	}

	// Returns the shapes
	const vector<DrawingShape*>& getShapes() {
		return shape;
	}

	// Reads the shapes from the file
	void readFile(fstream& inFile){
		Shapes inS;
		while (inFile.read(reinterpret_cast<char*>(&inS), sizeof(inS))){
			addShape(Vector2f(inS.x, inS.y), inS.shape, Color(inS.color));
		}
	}

	// Writes the shapes to the file
	void writeFile(fstream& outFile){
		for (int i = 0; i < shape.size(); i++){
			outFile.write(reinterpret_cast<char*>(&shape[i]->getFile()), sizeof(Shapes));
		}
	}



};