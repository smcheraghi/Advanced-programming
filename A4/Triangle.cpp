/*
* Implementation of concrete class Triangle which inherit from abstract class Shape
*/

#include "Triangle.h"

/*
* Constructor set initial value of height and base for Triangle object and call shape constructor by passing name and description of ractangle
* @param tBase: base of the Triangle
* @param tHeight: height of the Triangle
* @param sName: name of Triangle
* @param sDescription: description of Triangle
*/
Triangle::Triangle(int tBase, int tHeight,string sName, string sDiscription) : Shape(sName, sDiscription) {
    this->base = tBase;
    this->height = tHeight;
}

/*
* Compute Triangle area
* @return Triangle area
*/
double Triangle::computeGeoArea() const
{
    return ((double(this->height) * this->base) / 2);
}

/*
* Return the height of the Triangle's bounding box
* @return Triangle height
*/
int Triangle::getHeight() const
{
    return this->height;
}

/*
* Return the base of the Triangle
* @return Triangle width
*/
int Triangle::getWidth() const
{
    return this->base;
}

