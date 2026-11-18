
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generic Stack Class
template <class T>
class Stack {
private:
    vector<T> arr;

public:
    // Push element into stack
    void push(T value) {
        arr.push_back(value);
        cout << value << " pushed into stack." << endl;
    }

    // Pop element from stack
    void pop() {
        if (arr.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << arr.back() << " popped from stack." << endl;
            arr.pop_back();
        }
    }

    // Display stack elements
    void display() {
        if (arr.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = arr.size() - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    // Integer Stack
    cout << "\n--- Integer Stack ---" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.pop();

    // Float Stack
    cout << "\n--- Float Stack ---" << endl;
    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.push(30.5);
    s2.display();
    s2.pop();

    // String Stack
    cout << "\n--- String Stack ---" << endl;
    Stack<string> s3;
    s3.push("Apple");
    s3.push("Banana");
    s3.push("Mango");
    s3.display();
    s3.pop();

    return 0;
}
