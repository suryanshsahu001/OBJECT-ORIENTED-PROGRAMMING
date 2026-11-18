
#include <iostream>
using namespace std;

// Base class
class Person {
public:
    string name;
    int age;

    void getPersonDetails() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Single Inheritance: Student inherits Person
class Student : public Person {
public:
    int rollNo;
    string course;

    void getStudentDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Course: ";
        cin >> course;
    }

    void displayStudentDetails() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Course: " << course << endl;
    }
};

// Multilevel Inheritance: GraduateStudent inherits Student
class GraduateStudent : public Student {
public:
    string researchTopic;

    void getGraduateDetails() {
        cout << "Enter Research Topic: ";
        cin >> researchTopic;
    }

    void displayGraduateDetails() {
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent g;

    cout << "Enter Graduate Student Details\n";

    g.getPersonDetails();
    g.getStudentDetails();
    g.getGraduateDetails();

    cout << "\n--- Graduate Student Information ---\n";

    g.displayPersonDetails();
    g.displayStudentDetails();
    g.displayGraduateDetails();

    return 0;
}
