#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include<string>
#include<vector>

using namespace std;
using Grid = vector<vector<char>>;

class Shape {
private:
	static int generate_Id;												// Identity number generator
	int shapeId;														// Identity number
	string shapeName;													// Name of shape
	string shapeDescription;											// Description of shape

public:
	Shape(string sName, string sDescription);							// 1. Constructor set initial value of name and description for shape
	virtual ~Shape() = default;											// Destructor
	int getShapeId() const;												// 2. Get shape's ID
	string getShapeName() const;										// 2. Get shape's name
	string getShapeDescription() const;									// 2. Get shape's description	
	void setShapeName(string name);										// 3. Set shape's name
	void setShapeDescription(string description);						// 3. Set shape's description 
	string toString() const;											// 4. Generate represention of the shape
	
	virtual double computeGeoArea() const = 0;							// 5. Compute shape area
	virtual double computeGeoPerimeter() const = 0;						// 6. Compute shape perimeter
	virtual int computeScrArea() const = 0;								// 7. Compute shape screen area refer to the number of characters form the texual image of the shape
	virtual int computeScrPerimeter() const = 0;						// 8. Compute shape screen primeter refer to the number of characters on the borders of the texual image of the shape
	virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0;	// 9. Draw a texual image of the shape on a two dimentional grid 
	virtual int getHeight() const = 0;									// 10. Return the height of the shape's bounding box
	virtual int getWidth() const = 0;									// 11. Return the width of the shape's bounding box

};
ostream& operator<< (ostream& out, const Shape& s);						// Operator << overloading for shape
ostream& operator<< (ostream& out, const Grid& g);						// Operator << overloading for Grid
#endif 





//	virtual void drawTextualImage() const = 0;										
//	friend ostream& operator<< (ostream& out, const Grid& g);