#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"
#include <string>

class Rhombus : public Shape
{
private:
	int dim;																							// Dimention of rhombus 
public:
	Rhombus(int d, string sName = "Diamond", string sDescription = "Parallelogram with equal sides");	// Constructor
	virtual ~Rhombus() = default;																		// Deconstructor
	// Inherited via Shape
	virtual double computeGeoArea() const override;											// 5. Compute Rhombus area
	virtual double computeGeoPerimeter() const override;									// 6. Compute Rhombus perimeter
	virtual int computeScrArea() const override;											// 7. Compute Rhombus screen area refer to the number of characters form the texual image of the shape
	virtual int computeScrPerimeter() const override;										// 8. Compute Rhombus screen primeter refer to the number of characters on the borders of the texual image of the shape
	virtual Grid draw(char fChar = '*', char bChar = ' ') const override;					// 9. Draw a texual image of the Rhombus on a two dimentional grid 
	virtual int getHeight() const override;													// 10. Return the height of the Rhombus's bounding box
	virtual int getWidth() const override;													// 11. Return the width of the Rhombus's bounding box
};

#endif 