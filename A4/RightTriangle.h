#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"
#include <string>

class RightTriangle : public Triangle
{
public:
	RightTriangle(int tBase, string sName = "Ladder", string sDescription = "One right and two acute angles");		// Constructor
	virtual ~RightTriangle() = default;																		// Deconstructor
	// Inherited via Triangle
	virtual double computeGeoPerimeter() const override;									// 6. Compute RightTriangle perimeter
	virtual int computeScrArea() const override;											// 7. Compute RightTriangle screen area refer to the number of characters form the texual image of the shape
	virtual int computeScrPerimeter() const override;										// 8. Compute RightTriangle screen primeter refer to the number of characters on the borders of the texual image of the shape
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;					// 9. Draw a texual image of the RightTriangle on a two dimentional grid 

};

#endif 