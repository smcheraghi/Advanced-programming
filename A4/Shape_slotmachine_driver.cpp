/**
* This is the driver for shape, rectangle, rhombus, acute and right triangle samples and slot machine
* @Author: Seyed Mohammad Cheraghi
*/

#include "SlotMachine.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include <iostream>

void poly_draw_shape_by_ref(const Shape& shape, char foreground = '*', char background = ' ');
void poly_draw_shape_by_ptr(const Shape* pShape, char foreground = '*', char background = ' ');
int main1sample();												// Example codes from page 6 to 11 
int main2ref();													// Example of calling the draw function polymorphically through Shape&
int main3ptr();													// Example of calling the draw function polymorphically through Shape*
int main4unique_ptr();											// Example of calling the draw function polymorphically using unique_ptr

int main()
{
	main1sample();												// Example codes from page 6 to 11 
	main2ref();													// Example of calling the draw function polymorphically through Shape&
	main3ptr();													// Example of calling the draw function polymorphically through Shape*
	main4unique_ptr();											// Example of calling the draw function polymorphically using unique_ptr		
	
	SlotMachine slot_machine;									// Create a slot machine object
	slot_machine.run();											// Run our slot machine until the player decides
	return 0;													// To stop, or until the player runs out of tokens
}

int main1sample()
{
	Rectangle rect(5, 7);
	cout << rect.toString() << endl;
//	cout << rect <<endl;
	
	Rhombus ace(16, "Ace", "Ace of diamond");
	//cout << ace.toString() << endl;
	cout << ace << endl;

	AcuteTriangle at{ 17 };
	cout << at << endl;

	/*Shape* atptr = &at;
	cout << *atptr << endl;

	Shape& atref = at;
	cout << atref << endl;*/

	RightTriangle rt{ 10, "Carpenter's square"};
	cout << rt;

	Grid aceBox =  ace.draw('+', '.');
	cout << aceBox << endl;

	Grid rectBox = rect.draw();
	cout << rectBox << endl;

	Grid atBox = at.draw('^');
	cout << atBox << endl;

	Grid rtBox = rt.draw('-');
	cout << rtBox << endl;

	rtBox = rt.draw('\\', 'o');
	cout << rtBox << endl;

	aceBox = ace.draw('o');
	cout << aceBox << endl;

	return 0;
}


void poly_draw_shape_by_ref(const Shape& shape, char foreground, char background)
{
	Grid shape_box = shape.draw(foreground, background);
	cout << shape_box << endl;
}

int main2ref()
{
	Rectangle rect{ 5, 7 };
	Rhombus ace{ 16, "Ace", "Ace of diamond" };
	AcuteTriangle at{ 17 };
	RightTriangle rt{ 10, "Carpenter's square" };
	poly_draw_shape_by_ref(rect);
	poly_draw_shape_by_ref(ace, '+', '.');
	poly_draw_shape_by_ref(at, '^');
	poly_draw_shape_by_ref(rt, '-');
	return 0;
}


void poly_draw_shape_by_ptr(const Shape* pShape, char foreground, char background)
{
	Grid shape_box = pShape->draw(foreground, background);
	cout << shape_box << endl;
}

int main3ptr()
{
	Shape* pRect = new Rectangle{ 5, 7 };
	Shape* pAce = new Rhombus { 16, "Ace", "Ace of diamond" };
	Shape* pAt = new AcuteTriangle{ 17 };
	Shape* pRt = new RightTriangle{ 10, "Carpenter's square" };
	poly_draw_shape_by_ptr(pRect);
	poly_draw_shape_by_ptr(pAce, '+', '.');
	poly_draw_shape_by_ptr(pAt, '^');
	poly_draw_shape_by_ptr(pRt , '-');
	delete pRect;
	delete pAce;
	delete pAt;
	delete pRt;
	return 0;
}
	
	
int main4unique_ptr()
{
	std::unique_ptr<Shape> rectShape{ new Rectangle{5, 7} };
	Grid rectBox = rectShape->draw();
	cout << rectBox << endl;

	std::unique_ptr<Shape> aceShape{ new Rhombus{16, "Ace", "Ace of diamond"} };
	Grid aceBox = aceShape->draw('+', '.');
	cout << aceBox << endl;

	std::unique_ptr<Shape> atShape{ new AcuteTriangle(17) };
	Grid atBox = atShape->draw('^');
	cout << atBox << endl;

	std::unique_ptr<Shape> rtShape{ new RightTriangle(10, "Carpenter's square") };
	Grid rtBox = rtShape->draw('-');
	cout << rtBox << endl;
	// no need to delete any resources!
	// Notice that are 4 calls to the new operator but NONE to the delete operator
	return 0;
	}
	