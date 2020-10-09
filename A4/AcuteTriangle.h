#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Triangle.h"
#include <string>

class AcuteTriangle : public Triangle
{
private:
	int computHeight(int b);														// Compute height of AcuteTriangle
	int computBase(int b);															// Compute base of AcuteTriangle

public:
	AcuteTriangle(int tBase, string sName = "Wedge", string sDescription = "Three acute angles");	// Constructor
	virtual ~AcuteTriangle() = default;													// Deconstructor
	// Inherited via Triangle
	virtual double computeGeoPerimeter() const override;							// 6. Compute AcuteTriangle perimeter
	virtual int computeScrArea() const override;									// 7. Compute AcuteTriangle screen area refer to the number of characters form the texual image of the shape
	virtual int computeScrPerimeter() const override;								// 8. Compute AcuteTriangle screen primeter refer to the number of characters on the borders of the texual image of the shape
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;			// 9. Draw a texual image of the AcuteTriangle on a two dimentional grid 
	
};

#endif 