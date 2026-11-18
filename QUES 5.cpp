
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
};

// Derived Class: Circle
class Circle : public Shape {
public:
    double radius;

    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14 * radius * radius;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
public:
    double length, breadth;

    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
};

// Derived Class: Triangle
class Triangle : public Shape {
public:
    double base, height;

    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(4, 5);

    // Base class pointers
    Shape *s;

    s = &c;
    cout << "Area of Circle: " << s->area() << endl;

    s = &r;
    cout << "Area of Rectangle: " << s->area() << endl;

    s = &t;
    cout << "Area of Triangle: " << s->area() << endl;

    return 0;
}
