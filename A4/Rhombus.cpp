/*
* Implementation of concrete class Rhombus which inherit from abstract class Shape
*/

#include "Rhombus.h"
#include <string>
#include<math.h>

using namespace std;

/*
* Constructor set initial value of dim for Rhombus object and call shape constructor by passing name and description of Rhombus
* @param d: height of the Rhombus
* @param sName: name of Rhombus
* @param sDescription: description of Rhombus
*/
Rhombus::Rhombus(int d, string sName, string sDescription) : Shape(sName, sDescription) {
	if (d % 2 == 0) {
		this->dim = d + 1;
	}
	else {
		this->dim = d;
	}
}

/*
* Compute Rhombus area
* @return Rhombus area
*/
double Rhombus::computeGeoArea() const
{
	return ( ( double(this->dim) * this->dim )  / 2 );
}

/*
* Compute Rhombus perimeter
* @return Rhombus perimeter
*/
double Rhombus::computeGeoPerimeter() const
{
	return ( ( double(2) * sqrt(2) ) * this->dim );
}

/*
* Compute Rhombus screen area refer to the number of characters form the texual image of the shape
* @return Rhombus screen area
*/
int Rhombus::computeScrArea() const
{
	int n = floor(this->dim / 2);
	return ( ( 2 * n * (n + 1) ) + 1 );
}

/*
* Compute Rhombus screen primeter refer to the number of characters on the borders of the texual image of the shape
* @return Rhombus screen perimeter
*/
int Rhombus::computeScrPerimeter() const
{
	return ( 2 * ( this->dim - 1 ) );
}

/*
* Draw a texual image of the Rhombus on a two dimentional grid
* @param fChar: foreground
* @param bChar: background
* @return image of the rectangle
*/
Grid Rhombus::draw(char fChar, char bChar) const
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
		if (scope == center - 1) {
			flag = false;
		}
		if (flag) {
			oddNum = oddNum + 2;
		}
		else {
			oddNum = oddNum - 2;
		}


	}

	return tempGrid;
}

/*
* Return the height of the Rhombus's bounding box
* @return rectangle height
*/
int Rhombus::getHeight() const
{
	return this->dim;
}

/*
* Return the width of the Rhombus's bounding box
* @return rectangle width
*/
int Rhombus::getWidth() const
{
	return this->dim;
}

