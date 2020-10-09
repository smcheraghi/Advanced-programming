#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

class Triangle : public Shape
{
private:
	int base;																// Base of Triangle
	int height;																// Height of Triangle

public:
	Triangle(int base, int height, string sName, string sDiscription);		// Constructor
	virtual ~Triangle() = default;											// Deconstructor
	// Inherited via Shape
	virtual double computeGeoArea() const override;							// 5. Compute Triangle area
	virtual int getHeight() const override;									// 10. Return the height of the Triangle's bounding box
	virtual int getWidth() const override;									// 11. Return the base of the Triangle's bounding box		

};

#endif 