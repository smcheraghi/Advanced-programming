#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape 
{
private:
	int height;
	int width;
public:
	Rectangle(int w, int h, string sName = "Rectangle", string sDescription = "Four right angles");		// Constructor
	virtual ~Rectangle() = default;																	// Deconstructor
	// Inherited via Shape
	virtual double computeGeoArea() const override;									// 5. Compute Rectangle area
	virtual double computeGeoPerimeter() const override;							// 6. Compute Rectangle perimeter
	virtual int computeScrArea() const override;									// 7. Compute Rectangle screen area refer to the number of characters form the texual image of the shape
	virtual int computeScrPerimeter() const override;								// 8. Compute Rectangle screen primeter refer to the number of characters on the borders of the texual image of the shape
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;			// 9. Draw a texual image of the Rectangle on a two dimentional grid 
	virtual int getHeight() const override;											// 10. Return the height of the Rectangle's bounding box
	virtual int getWidth() const override;											// 11. Return the width of the Rectangle's bounding box
};

#endif 