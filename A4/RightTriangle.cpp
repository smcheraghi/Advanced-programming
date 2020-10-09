/*
* Implementation of concrete class RightTriangle which inherit from abstract class Shape
*/
#include "RightTriangle.h"
#include "Triangle.h"

/*
* Constructor set initial value of dim for RightTriangle object and call shape constructor by passing name and description of RightTriangle
* @param d: height of the RightTriangle
* @param sName: name of RightTriangle
* @param sDescription: description of RightTriangle
*/
RightTriangle::RightTriangle(int tBase, string sName, string sDescription) : Triangle(tBase, tBase, sName, sDescription) {}

/*
* Compute RightTriangle perimeter
* @return RightTriangle perimeter
*/
double RightTriangle::computeGeoPerimeter() const
{
	return (( double(2) + double(sqrt(2)) ) * this->getHeight());
}

/*
* Compute RightTriangle screen area refer to the number of characters form the texual image of the shape
* @return RightTriangle screen area
*/
int RightTriangle::computeScrArea() const
{
	return (this->getHeight() * (this->getHeight() + 1 ) / 2);
}

/*
* Compute RightTriangle screen primeter refer to the number of characters on the borders of the texual image of the shape
* @return RightTriangle screen perimeter
*/
int RightTriangle::computeScrPerimeter() const
{
	return (3 * (this->getHeight() - 1));
}

/*
* Draw a texual image of the RightTriangle on a two dimentional grid
* @param fChar: foreground
* @param bChar: background
* @return image of the RightTriangle
*/
Grid RightTriangle::draw(char fChar, char bChar) const
{
	Grid tempGrid;
	for (int i = 1; i < this->getHeight() + 1; i++) {
		vector<char> row;
		int counter = 1;
		for (int j = 1; j < this->getWidth() + 1; j++) {
			if (counter <= i) {
				row.push_back(fChar);
				++counter;
			}
			else {
				row.push_back(bChar);
			}
		}
		tempGrid.push_back(row);
	}
	return tempGrid;
}


