/*
* Implementation of concrete class AcuteTriangle which inherit from abstract class Shape
*/
#include "AcuteTriangle.h"
#include "Triangle.h"

/*
* Constructor set initial value of dim for AcuteTriangle object and call shape constructor by passing name and description of AcuteTriangle
* @param d: height of the AcuteTriangle
* @param sName: name of AcuteTriangle
* @param sDescription: description of AcuteTriangle
*/
AcuteTriangle::AcuteTriangle(int tBase, string sName, string sDescription) : Triangle(computBase(tBase), computHeight(tBase), sName, sDescription) {}

/*
* Compute the base of AcuteTriangle
* @param b
* @return b: base of AcuteTriangle
*/
int AcuteTriangle::computBase(int b) {
	if (b % 2 == 0) {
		return (b + 1);
	}
	else {
		return b;
	}
}

/*
* Compute the height of AcuteTriangle
* @param b
* @return b: height of AcuteTriangle
*/
int AcuteTriangle::computHeight(int b) {
	int tHeight;
	if (b % 2 == 0) {
		b = b + 1;
	}
	tHeight = ((b + 1) / 2);
	return tHeight;
}

/*
* Compute AcuteTriangle perimeter
* @return AcuteTriangle perimeter
*/
double AcuteTriangle::computeGeoPerimeter() const
{
	return ( double(this->getWidth()) + sqrt( ( double(this->getWidth()) * this->getWidth() ) + ( double(4) * ( double(this->getHeight()) * this->getHeight() ) ) ) );
}

/*
* Compute AcuteTriangle screen area refer to the number of characters form the texual image of the shape
* @return AcuteTriangle screen area
*/
int AcuteTriangle::computeScrArea() const
{
	return (this->getHeight() * this->getHeight());
}

/*
* Compute AcuteTriangle screen primeter refer to the number of characters on the borders of the texual image of the shape
* @return AcuteTriangle screen perimeter
*/
int AcuteTriangle::computeScrPerimeter() const
{
	return ( 4 * ( this->getHeight() - 1 ) );
}

/*
* Draw a texual image of the AcuteTriangle on a two dimentional grid
* @param fChar: foreground
* @param bChar: background
* @return image of the AcuteTriangle
*/
Grid AcuteTriangle::draw(char fChar, char bChar) const
{
	Grid tempGrid;
	bool flag = true;
	int oddNum = 1;
	int center = ((this->getWidth() - 1) / 2) + 1;
	int scope;
	for (int i = 1; i < this->getHeight() + 1; i++) {
		scope = (oddNum - 1) / 2;
		vector<char> row;
		for (int j = 1; j < this->getWidth() + 1; j++) {
			if ((center - scope) <= j && j <= (center + scope)) {
				row.push_back(fChar);
			}
			else
			{
				row.push_back(bChar);
			}
		}
		tempGrid.push_back(row);
		oddNum = oddNum + 2;
	}
	return tempGrid;
}


