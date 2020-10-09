#include "Shape.h"
#include <string>
#include <sstream>
#include <iomanip>
#include<typeinfo>

using namespace std;

/*
* Initializing the generate_ID
*/
int Shape::generate_Id{ 1 };						

/*
* Constructor set initial value of name and description for shape
* @param name: name of the shape
* @param description: description of the shape
*/
Shape::Shape(string name, string description) {
	this->shapeId = this->generate_Id++;
	this->shapeName = name;
	this->shapeDescription = description;
}

/*
* Getter method for the shape's ID
* @return shapeId
*/
int Shape::getShapeId() const {
	return this->shapeId;
}

/*
* Getter method for the shape's name
* @return shapeName
*/
string Shape::getShapeName() const {
	return this->shapeName;
}

/*
* Getter method for the shape's description
* @return shapeDescription
*/
string Shape::getShapeDescription() const {
	return this->shapeDescription;
}

/*
* Setter method for the shape's name
* @Param name: name of shape
*/
void Shape::setShapeName(string name) {
	this->shapeName = name;
}

/*
* Setter method for the shape's description
* @param description: description of shape
*/
void Shape::setShapeDescription(string description) {
	this->shapeDescription = description;
}

/*
* Generate represention of the shape
* @return strign: representation of shape
*/
string Shape::toString() const
{
	std::stringstream myStream;
	int str_w_size = 15;
	myStream.setf(std::ios::fixed, std::ios::floatfield);
	myStream << "Shape Information" << endl;
	myStream << "-----------------" << endl;
	myStream << std::left << std::setw(str_w_size) << "id:" << std::setw(str_w_size) << this->getShapeId() << endl;
	myStream << std::left << std::setw(str_w_size) << "Shape name:" << std::setw(str_w_size) << this->getShapeName() << endl;
	myStream << std::left << std::setw(str_w_size) << "Description:" << std::setw(str_w_size) << this->getShapeDescription() << endl;
	myStream << std::left << std::setw(str_w_size) << "B. box width:" << std::setw(str_w_size) << this->getWidth() << endl;
	myStream << std::left << std::setw(str_w_size) << "B. box height:" << std::setw(str_w_size) << this->getHeight() << endl;
	myStream << std::left << std::setw(str_w_size) << "Scr area:" << std::setw(str_w_size) << this->computeScrArea() << endl;
	myStream << std::left << std::setw(str_w_size) << "Geo area:" << std::setw(str_w_size) << setprecision(2) << this->computeGeoArea() << endl;
	myStream << std::left << std::setw(str_w_size) << "Scr perimeter:" << std::setw(str_w_size) << this->computeScrPerimeter() << endl;
	myStream << std::left << std::setw(str_w_size) << "Geo perimeter:" << std::setw(str_w_size) << setprecision(2) << this->computeGeoPerimeter() << endl;
	myStream << std::left << std::setw(str_w_size) << "Static type:" << std::setw(str_w_size) << typeid(this).name() << endl;
	myStream << std::left << std::setw(str_w_size) << "Dynamic type:" << std::setw(str_w_size) << typeid(*this).name() << endl;

	return myStream.str();
}

/*
* Operator << overloading for shape object
* @param out
* @param s
*/
ostream& operator<< (ostream& out, const Shape& s) {
	out << s.toString();
	return out;
}

/*
* Operator << overloading for Grid object
* @param out
* @param g
*/
ostream& operator<< (ostream& out, const Grid& g) {
	for (int i = 0; i < g.size(); i++) {
		out << endl;
		for (int j = 0; j < g[i].size(); j++) {
			out << g[i][j];
		}
	}
	return out;
}

