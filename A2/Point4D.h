#ifndef POINT4D_H
#define POINT4D_H

#include <array>
#include <string>

using namespace std;

class Point4D {
private:
	array<double, 4> point;
	static double tolerance;
public:
	Point4D();																		// Default ctr
	explicit Point4D(double p1);													// Ctr with one parameter
	Point4D(double p1, double p2);													// Ctr with two parameter
	Point4D(double p1, double p2, double p3);										// Ctr with three parameter
	Point4D(double p1, double p2, double p3, double p4);							// Ctr with four parameter
	Point4D(const Point4D& p) = default;											// Defaulted copy ctr
	Point4D& operator=(const Point4D&) = default;									// Defaulted assignment operator
	virtual ~Point4D() = default;													// Defaulted destructor
	static void setTolerance(double tol);											// Set tolerance
	static double getTolerance();													// Get tolerance
	void toStream(std::ostream& sout) const;										// To string the points			
	array<double, 4> getPoint() const;												// Return the point array	
	const double getPoint(int index) const;											// Return the point by index
	void setPoint(int index, double value);											// Set the point by index and value
	double absValue();																// Return the absolute value		
	double getDetermin() const;														// Calculate the deterinant
	Point4D inverse() const;														// Calculate the inverse	
	Point4D& operator+= (const Point4D& p);											// Compound assignment operators +=
	Point4D& operator-= (const Point4D& p);											// Compound assignment operators -= 
	Point4D& operator*= (const Point4D& p);											// Compound assignment operators *=
	Point4D& operator/= (const Point4D& p);											// Compound assignment operators /=
	Point4D& operator+= (const double p);											// Compound assignment operators +=
	Point4D& operator-= (const double p);											// Compound assignment operators -=	
	Point4D& operator*= (const double p);											// Compound assignment operators *=
	Point4D& operator/= (const double p);											// Compound assignment operators /=		
	Point4D operator+ ();															// Unary operators +
	Point4D operator- ();															// Unary operators -
	Point4D& operator++ ();															// Unary operators ++
	Point4D& operator-- ();															// Unary operators --
	Point4D operator++ (int);														// Unary operators ++, post increment
	Point4D operator-- (int);														// Unary operators ++, post decrement
	const double operator[] (int a) const;											// Subscript operator[] const
	double& operator[] (int a);														// Subscript operator[] non const	
	double operator() ();															// Function call operator() overload
	bool operator! ();																// Logical not
};	// End of the class																					

Point4D operator+ (const Point4D& p1, const Point4D& p2);							// Basic arithmetic operators +
Point4D operator- (const Point4D& p1, const Point4D& p2);							// Basic arithmetic operators -		
Point4D operator* (const Point4D& p1, const Point4D& p2);							// Basic arithmetic operators *
Point4D operator/ (const Point4D& p1, const Point4D& p2);							// Basic arithmetic operators /	
Point4D operator+ (const Point4D& p1, const double a);								// Basic arithmetic operators +	
Point4D operator- (const Point4D& p1, const double a);								// Basic arithmetic operators -
Point4D operator* (const Point4D& p1, const double a);								// Basic arithmetic operators *
Point4D operator/ (const Point4D& p1, const double a);								// Basic arithmetic operators /
Point4D operator+ (const double a, const Point4D& p1);								// Basic arithmetic operators +
Point4D operator- (const double a, const Point4D& p1);								// Basic arithmetic operators -
Point4D operator* (const double a, const Point4D& p1);								// Basic arithmetic operators *
Point4D operator/ (const double a, const Point4D& p1);								// Basic arithmetic operators /
bool operator== (const Point4D& p1, const Point4D& p2);								// Relational operators ==
bool operator!= (const Point4D& p1, const Point4D& p2);								// Relational operators !=
bool operator< (const Point4D, const Point4D);										// Relational operators <	
bool operator<= (const Point4D, const Point4D);										// Relational operators <=
bool operator> (const Point4D, const Point4D);										// Relational operators >
bool operator>= (const Point4D, const Point4D);										// Relational operators >=
std::ostream& operator<<(std::ostream& sout, Point4D& p);							// Overloaded output operator <<
std::istream& operator>>(std::istream& sin, Point4D& p);							// Overloaded input operator >>

#endif 