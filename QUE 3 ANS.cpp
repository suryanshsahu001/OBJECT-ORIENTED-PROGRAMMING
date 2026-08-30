#include <iostream>
using namespace std;

class Number {
    int num;

public:
    // Default constructor
    Number() : num(0) {}

    // Parameterized constructor
    Number(int n) : num(n) {}

    // Copy constructor
    Number(const Number &n) : num(n.num) {}

    // Move constructor
    Number(Number &&n) : num(n.num) {
        n.num = 0;
    }

    // Copy assignment
    Number& operator=(const Number &n) {
        num = n.num;
        return *this;
    }

    // Move assignment
    Number& operator=(Number &&n) {
        num = n.num;
        n.num = 0;
        return *this;
    }

    // Destructor
    ~Number() {}

    void display() {
        cout << num << endl;
    }
};

int main() {
    Number n1;           // Default
    Number n2(25);       // Parameterized
    Number n3(n2);       // Copy
    Number n4(move(n2)); // Move

    n1.display();
    n2.display();
    n3.display();
    n4.display();

    return 0;
}