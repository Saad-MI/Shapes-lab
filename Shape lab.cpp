#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Shapes {

public:
	double getArea() {
		return 0;
	}

	double getPerimeter() {
		return 0;
	}
};


class Circle : public Shapes {
protected:
	double radius;
public:
	Circle(double r)
		: radius(r){}

	double getArea() {
		return 3.1415 * radius * radius;

	}

	double getPerimeter() {
		return 2 * 3.1415 * radius;
	}
};


class Rectangle : public Shapes {
	protected:
		double width;
		double height;
public:
	Rectangle(double w, double h)
		: width(w), height(h) {}
		
	double getArea() {
		return width * height;
	}

	double getPerimeter() {
		return 2 * (height + width );
	}
};


class RightTriangle : public Shapes {

protected:
	double base;
	double height;

public:
	RightTriangle(double b, double h):

	base(b), height(h) {}
	double getArea() {
		return .5 * base * height;
	}

	double getPerimeter() {
		return base + height + sqrt(pow(base, 2) + pow(height, 2));
	}
};


class Square : public Rectangle {
public:
	Square(double s) :
		Rectangle(s, s) {
	}
	};


class IsocelesRightTriangle : public RightTriangle {
	public:
		IsocelesRightTriangle(double l)
			: RightTriangle(l, l){}
};

int main()
{
	Square square(5);
	assert(square.getArea() == 25);


	assert(square.getPerimeter() == 20);

	Shapes shape;
	assert(shape.getArea() == 0);

	assert(shape.getPerimeter() == 0);

	IsocelesRightTriangle i(5);
	assert(i.getArea() == 12.5);


	Circle circle(2);

	assert(circle.getArea() == 3.1415 * 2 * 2);


	assert(circle.getPerimeter() == 2 * 3.1415 * 2);

	Rectangle rectangle(3, 4);
	assert(rectangle.getArea() == 12);
	assert(rectangle.getPerimeter() == 14);

	RightTriangle triangle(3, 4);


	assert(triangle.getArea() == 6);

	assert(triangle.getPerimeter() == 12);

	cout << "tests passed" << endl;
}

