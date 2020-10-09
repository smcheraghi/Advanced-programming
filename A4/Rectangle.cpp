/*
* Implementation of concrete class rectangle which inherit from abstract class Shape
*/

#include "Rectangle.h"
#include <string>

using namespace std;

/*
* Constructor set initial value of height and width for rectangle object and call shape constructor by passing name and description of ractangle
* @param h: height of the rectangle
* @param w: width of the rectangle
* @param sName: name of rectangle
* @param sDescription: description of rectangle
*/
Rectangle::Rectangle(int w, int h, string sName, string sDescription) : Shape(sName, sDescription) {
	this->height = h;
	this->width = w;
}

/*
* Compute rectangle area
* @return rectangle area
*/
double Rectangle::computeGeoArea() const
{
	return (double(this->height) * this->width);
}

/*
* Compute rectangle perimeter
* @return rectangle perimeter
*/
double Rectangle::computeGeoPerimeter() const
{
	return (2 * (double(this->height) + this->width));
}

/*
* Compute rectangle screen area refer to the number of characters form the texual image of the shape
* @return rectangle screen area
*/
int Rectangle::computeScrArea() const
{
	return (this->height * this->width);
}

/*
* Compute rectangle screen primeter refer to the number of characters on the borders of the texual image of the shape
* @return rectangle screen perimeter
*/
int Rectangle::computeScrPerimeter() const
{
	return ((2 * (this->height + this->width)) - 4 );
}

/*
* Draw a texual image of the rectangle on a two dimentional grid
* @param fChar: foreground
* @param bChar: background
* @return image of the rectangle
*/
Grid Rectangle::draw(char fChar, char bChar) const
{
	Grid tempGrid;
	for (int i = 0; i < this->getHeight(); i++) {
		vector<char> tempVec;
		for (int j = 0; j < this->getWidth(); j++) {
			tempVec.push_back(fChar);
		}
		tempGrid.push_back(tempVec);
	}
	return tempGrid;
}

/*
* Return the height of the rectangle's bounding box
* @return rectangle height
*/
int Rectangle::getHeight() const
{
	return this->height;
}

/*
* Return the width of the rectangle's bounding box
* @return rectangle width
*/
int Rectangle::getWidth() const
{
	return this->width;
}

