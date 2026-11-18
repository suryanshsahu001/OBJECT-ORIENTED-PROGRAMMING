
#include <iostream>
using namespace std;

class Complex {
public:
    float real, imag;

    // Constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Function Overloading
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    void display(string message) {
        cout << message;
        cout << real << " + " << imag << "i" << endl;
    }

    // Operator Overloading (+)
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
};

int main() {
    Complex c1(5, 3);
    Complex c2(2, 4);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    // Adding two complex numbers
    Complex c3 = c1 + c2;

    cout << "Addition: ";
    c3.display();

    // Function Overloading
    c3.display("Result: ");

    return 0;
}
