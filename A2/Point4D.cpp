/* ==========================================================================================================================================================================
*   Seyed Mohammad Cheraghi 
*	Create an abstract data type (ADT)
*	Implement the ADT, using the operator overloading facility of the C++ language using array rather than raw dumb arrays.
* ===========================================================================================================================================================================
*/

#include "Point4D.h"
#include<iostream>
#include <cmath>
#include <string>

using namespace std;

/*
* Default constructor
*/
Point4D::Point4D() {
	this->point[0] = 0;
	this->point[1] = 0;
	this->point[2] = 0;
	this->point[3] = 0;
}

/*
* Constructor with one parameter
* @param p1
*/
Point4D::Point4D(double p1) {
	this->point[0] = p1;
	this->point[1] = 0;
	this->point[2] = 0;
	this->point[3] = 0;
}

/*
* Constructor with two parameter
* @param p1
* @param p2
*/
Point4D::Point4D(double p1, double p2) {
	this->point[0] = p1;
	this->point[1] = p2;
	this->point[2] = 0;
	this->point[3] = 0;
}

/*
* Constructor with three parameter
* @param p1
* @param p2
* @param p3
*/
Point4D::Point4D(double p1, double p2, double p3) {
	this->point[0] = p1;
	this->point[1] = p2;
	this->point[2] = p3;
	this->point[3] = 0;
}

/*
* Constructor with four parameter
* @param p1
* @param p2
* @param p3
* @param p4
*/
Point4D::Point4D(double p1, double p2, double p3, double p4) {
	this->point[0] = p1;
	this->point[1] = p2;
	this->point[2] = p3;
	this->point[3] = p4;
}

/*
* Initialize the static variable tolerance 
*/
double Point4D::tolerance = 1.0E-6;

/*
* Set the static variable tolerance
* @param tol
*/
void Point4D::setTolerance(double tol) {
	tolerance = std::abs(tol);
}

/*
* Get the static variable tolerance
* @return tolerance
*/
double Point4D::getTolerance() {
	return tolerance;
}

/*
* Print the Point4D data type in the format [x1, x2, x3, x4].
* @param sout
*/
void Point4D::toStream(std::ostream& sout) const{
	string s = "[" + std::to_string(this->point[0]) + ", " + std::to_string(this->point[1]) + ", " + std::to_string(this->point[2]) + ", " + std::to_string(this->point[3]) + "]";
	sout << s;
}

/*
* Return the array of points.
* @return point
*/
array<double, 4> Point4D::getPoint() const {
	return this->point;
}

/*
* Return the point by index.
* @param index
* @return point[index]
*/
const double Point4D::getPoint(int index) const {
	return this->point[index];
}

/*
* Set the point by index and value.
* @param index
* @param value
*/
void Point4D::setPoint(int index, double value) {
	this->point[index] = value;
}

/*
* Calculate the absolute value.
* @return absoluteValue
*/
double Point4D::absValue() {
	return (abs(point[0]) + abs(point[1]) + abs(point[2]) + abs(point[3]));
}

/*
* Get the determinant.
* @return determin
*/
double Point4D::getDetermin() const
{
	return (this->point[0] * this->point[2]) - (this->point[1] * this->point[3]);
}

/*
* Calculate the inversr of matrix.
* @return temp
*/
Point4D Point4D::inverse() const
{
	double det = getDetermin();
	if (abs(det) < getTolerance())
	{
		throw std::overflow_error("Encountered division by zero while inverting a Point4D");
	}
	else {
		double det_inverse = 1 / det;
		Point4D temp(*this);
		temp.point[0] = this->point[2];
		temp.point[1] = this->point[1] * (-1);
		temp.point[2] = this->point[0];
		temp.point[3] = this->point[3] * (-1);
		temp *= det_inverse;
		return temp;
	}
}


/*===========================================================================================================================================================================
*									Compound assignment operators. All are implemented as member functions. All modify their left-hand side operands.
* ===========================================================================================================================================================================
/*
* Compound assignment operators +=, takes one argument Point4D, add to the current Pont4D and modify the current with new value.
* @param p
* @return this
*/
Point4D& Point4D::operator+= (const Point4D& p) {
	this->point[0] += p.point[0];
	this->point[1] += p.point[1];
	this->point[2] += p.point[2];
	this->point[3] += p.point[3];
	return *this;
}

/*
* Compound assignment operators -=, takes one argument Point4D, subtract from the current Pont4D and modify the current with new value.
* @param p
* @return this
*/
Point4D& Point4D::operator-= (const Point4D& p) {
	this->point[0] -= p.point[0];
	this->point[1] -= p.point[1];
	this->point[2] -= p.point[2];
	this->point[3] -= p.point[3];
	return *this;
}

/*
* Compound assignment operators *=, takes one argument Point4D, multiply to the current Pont4D and modify the current with new value.
* @param p
* @return this
*/
Point4D& Point4D::operator*= (const Point4D& p) {
	Point4D temp(*this);
	temp.point[0] = (this->point[0] * p.point[0]) + (this->point[1] * p.point[3]);
	temp.point[1] = (this->point[0] * p.point[1]) + (this->point[1] * p.point[2]);
	temp.point[2] = (this->point[3] * p.point[1]) + (this->point[2] * p.point[2]);
	temp.point[3] = (this->point[3] * p.point[0]) + (this->point[2] * p.point[3]);
	this->point[0] = temp.point[0];
	this->point[1] = temp.point[1];
	this->point[2] = temp.point[2];
	this->point[3] = temp.point[3];
	return *this;
}

/*
* Compound assignment operators /=, takes one argument Point4D, multiply to the inverse of current Pont4D and modify the current with new value.
* @param p
* @return this
*/
Point4D& Point4D::operator/= (const Point4D& p) {
	*this *= p.inverse();
	return *this;
}

/*
* Compound assignment operators +=, takes one argument double, add to the current Pont4D and modify the current with new value.
* @param a
* @return this
*/
Point4D& Point4D::operator+= (const double a) {
	this->point[0] += a;
	this->point[1] += a;
	this->point[2] += a;
	this->point[3] += a;
	return *this;
}

/*
* Compound assignment operators -=, takes one argument double, subtract from the current Pont4D and modify the current with new value.
* @param a
* @return this
*/
Point4D& Point4D::operator-= (const double a) {
	this->point[0] -= a;
	this->point[1] -= a;
	this->point[2] -= a;
	this->point[3] -= a;
	return *this;
}

/*
* Compound assignment operators *=, takes one argument double, multiply to the current Pont4D and modify the current with new value.
* @param a
* @return this
*/
Point4D& Point4D::operator*= (const double a) {
	this->point[0] *= a;
	this->point[1] *= a;
	this->point[2] *= a;
	this->point[3] *= a;
	return *this;
}

/*
* Compound assignment operators /=, takes one argument double , inverse it, multiply to the current Pont4D and modify the current with new value.
* @param a
* @return this
*/
Point4D& Point4D::operator/= (const double a)
{
	if (a == 0) {
		cout << "Error: can not divide by zero ...";
	}
	else {
		double inverseOf_a = 1 / a;
		*this *= inverseOf_a;
	}
	return *this;
}

/*===========================================================================================================================================================================
*												Basic arithmetic operators. All are implemented as free (non-member) functions.
* ===========================================================================================================================================================================
*/
/*
* Basic arithmetic operators +, takes two argument double, add them together.
* @param p1
* @param p2
* @return temp
*/
Point4D operator+ (const Point4D& p1, const Point4D& p2) {
	Point4D temp(p1);
	temp += p2;
	return temp;
}

/*
* Basic arithmetic operators -, takes two argument double, subtract p2 from p1 --> p1 - p2.
* @param p1
* @param p2
* @return temp
*/
Point4D operator- (const Point4D& p1, const Point4D& p2) {
	Point4D temp(p1);
	temp -= p2;
	return temp;
}

/*
* Basic arithmetic operators *, takes two argument double, multiply p1 to p2.
* @param p1
* @param p2
* @return temp
*/
Point4D operator* (const Point4D& p1, const Point4D& p2) {
	Point4D temp(p1);
	temp *= p2;
	return temp;
}

/*
* Basic arithmetic operators /, takes two argument double, devide p1 by p2.
* @param p1
* @param p2
* @return temp
*/
Point4D operator/ (const Point4D& p1, const Point4D& p2) {
	Point4D temp(p1);
	return temp /= p2;
}

/*
* Basic arithmetic operators +, takes two argument, one Point4D, one double, add them together.
* @param p1
* @param a
* @return temp
*/
Point4D operator+ (const Point4D& p1, const double a) {
	Point4D temp(p1);
	temp += a;
	return temp;
}

/*
* Basic arithmetic operators -, takes two argument, one Point4D, one double, subtract double from point4D.
* @param p1
* @param a
* @return temp
*/
Point4D operator- (const Point4D& p1, const double a) {
	Point4D temp(p1);
	temp -= a;
	return temp;
}

/*
* Basic arithmetic operators *, takes two argument, one Point4D, one double, multiply to each other.
* @param p1
* @param a
* @return temp *= a
*/
Point4D operator* (const Point4D& p1, const double a) {
	Point4D temp(p1);
	return temp *= a;
}

/*
* Basic arithmetic operators ?, takes two argument, one Point4D, one double, multiply point4D to inverse of double arg.
* @param p1
* @param a
* @return p1*(1/a)
*/
Point4D operator/ (const Point4D& p1, const double a) {
	return p1 * (1 / a);
}

/*
* Basic arithmetic operators +, takes two argument, one double, one point4D, add them together.
* @param a
* @param p1
* @return p1+a
*/
Point4D operator+ (const double a, const Point4D& p1) {
	return p1 + a;
}

/*
* Basic arithmetic operators -, takes two argument, one double, one point4D, then subtract.
* @param a
* @param p1
* @return temp
*/
Point4D operator- (const double a, const Point4D& p1) {
	Point4D temp(p1);
	temp = -temp;
	temp += a;
	return temp;
}

/*
* Basic arithmetic operators *, takes two argument, one double, one point4D, multiply point4D to double.
* @param a
* @param p1
* @return p1*a
*/
Point4D operator* (const double a, const Point4D& p1) {
	return p1 * a;
}

/*
* Basic arithmetic operators /, takes two argument, one double, one point4D, multiply a to inverse of point4D.
* @param a
* @param p1
* @return a*p1.inverse()
*/
Point4D operator/ (const double a, const Point4D& p1) {
	return a * p1.inverse();
}


/*===========================================================================================================================================================================
*												Relational operators. None modifies its operands. All are implemented as free functions.
* ===========================================================================================================================================================================
*/
/*
* Relational operators ==, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator== (const Point4D& p1, const Point4D& p2) {
	Point4D temp(p1.getPoint(0) - p2.getPoint(0), p1.getPoint(1) - p2.getPoint(1), p1.getPoint(2) - p2.getPoint(2), p1.getPoint(3) - p2.getPoint(3));
	if (temp.absValue() <= p1.getTolerance())
	{
		return true;
	}
	return false;
}

/*
* Relational operators !=, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator!= (const Point4D& p1, const Point4D& p2){
	return !(p1 == p2);
}

/*
* Relational operators <, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator< (const Point4D p1, const Point4D p2) {
	array<double, 4> point_P1 = p1.getPoint();
	array<double, 4> point_P2 = p2.getPoint();
	double aboluteValue_p1 = abs(point_P1[0]) + abs(point_P1[1]) + abs(point_P1[2]) + abs(point_P1[3]);
	double aboluteValue_p2 = abs(point_P2[0]) + abs(point_P2[1]) + abs(point_P2[2]) + abs(point_P2[3]);
	if ((p1 != p2) && (aboluteValue_p1 < aboluteValue_p2))
		return true;
	return false;
}

/*
* Relational operators <=, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator<= (const Point4D p1, const Point4D p2) {
	array<double, 4> point_P1 = p1.getPoint();
	array<double, 4> point_P2 = p2.getPoint();
	if (p1 == p2 || p1 < p2) {
		return true;
	}
	return false;
}

/*
* Relational operators >, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator> (const Point4D p1, const Point4D p2) {
	array<double, 4> point_P1 = p1.getPoint();
	array<double, 4> point_P2 = p2.getPoint();
	double aboluteValue_p1 = abs(point_P1[0]) + abs(point_P1[1]) + abs(point_P1[2]) + abs(point_P1[3]);
	double aboluteValue_p2 = abs(point_P2[0]) + abs(point_P2[1]) + abs(point_P2[2]) + abs(point_P2[3]);
	if ((p1 != p2) && (aboluteValue_p1 > aboluteValue_p2))
		return true;
	return false;
}

/*
* Relational operators >=, compare two Point4D.
* @param p1
* @param p2
* @return boolean
*/
bool operator>= (const Point4D p1, const Point4D p2) {
	array<double, 4> point_P1 = p1.getPoint();
	array<double, 4> point_P2 = p2.getPoint();
	if (p1 == p2 || p1 > p2) {
		return true;
	}
	return false;
}

/*===========================================================================================================================================================================
*															Unary operators. All are implemented as members.
* ===========================================================================================================================================================================
*/
/*
* Unary operators +
* @return this
*/
Point4D Point4D::operator+ () {
	return *this;
}

/*
* Unary operators -
* @return temp
*/
Point4D Point4D::operator- () {
	Point4D temp(*this);
	temp.point[0] = -temp.point[0];
	temp.point[1] = -temp.point[1];
	temp.point[2] = -temp.point[2];
	temp.point[3] = -temp.point[3];
	return temp;
}

/*
* Unary operators ++, increment the current.
* @return this
*/
Point4D& Point4D:: operator++ () {
	*this += 1;
	return *this;
}

/*
* Unary operators ++, decrement the current.
* @return this
*/
Point4D& Point4D::operator-- () {
	*this -= 1;
	return *this;
}

/*
* Unary operators ++, post increment the current.
* @return temp
*/
Point4D Point4D::operator++ (int) {
	Point4D temp(*this);
	*this += 1;
	return temp;
}

/*
* Unary operators --, post decrement the current.
* @return temp
*/
Point4D Point4D::operator-- (int) {
	Point4D temp(*this);
	*this -= 1;
	return temp;
}

/*
* logical not operator !, check that the matrix is invertable or not
* @return bool
*/
bool Point4D::operator! () {
	if (this->getDetermin() == 0)
		return true;
	else
		return false;
}
/*===========================================================================================================================================================================
*																	Subscript operator[] (both const and non-const). 
* ===========================================================================================================================================================================
*/
/*
* Subscript operator[] const. Use 1-based indexing.
* @param a
* @return point
*/
const double Point4D::operator[] (int a) const {
	if (a == 1)
		return this->point[0];
	else if (a == 2)
		return this->point[1];
	else if (a == 3)
		return this->point[2];
	else if (a == 4)
		return this->point[3];
	else
		//throw out_of_range("index out of bounds");
		cout << "ERROR: The index is out of bounds, it should be between [1,4]" << endl;
}

/*
* Subscript operator[] non-const. Use 1-based indexing.
* @param a
* @return point
*/
double& Point4D::operator[] (int a) {
	if (a == 1)
		return this->point[0];
	else if (a == 2)
		return this->point[1];
	else if (a == 3)
		return this->point[2];
	else if (a == 4)
		return this->point[3];
	else
		cout << "ERROR: The index is out of bounds, it should be between [1,4]" << endl;
}


//Point4D Point4D::operator= (Point4D p) {
//	if (p == this)
//		return *this;
//	this->point[0] = p.point[0];
//	this->point[1] = p.point[1];
//	this->point[2] = p.point[2];
//	this->point[3] = p.point[3];
//	return *this;
//}

/*===========================================================================================================================================================================
*																			Function call operator() 
* ===========================================================================================================================================================================
*/
/*
* Function call operator() overload that takes no arguments and returns a double approximating the absolute value of the invoking object.
* return double
*/
double Point4D::operator() () {
	return this->absValue();
}

/*===========================================================================================================================================================================
*																			Overloaded input/output
* ===========================================================================================================================================================================
*/
/*
* Overloaded input operator >> for reading Point4D object.
* @param sin
* @param p
* @return sin
*/
std::istream& operator>>(std::istream& sin, Point4D& p) {
	array<double, 4> temp;
	cout << "enter four double value: " << endl;
	sin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
	p.setPoint(0, temp[0]);
	p.setPoint(1, temp[1]);
	p.setPoint(2, temp[2]);
	p.setPoint(3, temp[3]);
	return sin;
}

/*
* Overloaded output operator << for writing Point4D object.
* @param sout
* @param p
* @return sout
*/
std::ostream& operator<< (std::ostream& sout, Point4D& p) {
	p.toStream(sout);
	return sout;
}

