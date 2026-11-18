
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student Class
class Student {
public:
    int rollNo;
    string name;
    int age;
    float marks;

    // Constructor
    Student(int r, string n, int a, float m) {
        rollNo = r;
        name = n;
        age = a;
        marks = m;
    }

    // Display Student Details
    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nMarks: " << marks << endl;
    }
};

// Student Management Class
class StudentManagement {
private:
    vector<Student> students;

public:

    // Add Student
    void addStudent() {
        int roll, age;
        string name;
        float marks;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        // Check duplicate roll number
        for (auto &s : students) {
            if (s.rollNo == roll) {
                cout << "Student already exists!\n";
                return;
            }
        }

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(roll, name, age, marks));

        cout << "\nStudent Added Successfully!\n";
    }

    // Display All Students
    void displayStudents() {
        if (students.empty()) {
            cout << "\nNo Student Records Found!\n";
            return;
        }

        for (auto &s : students) {
            s.display();
        }
    }

    // Search Student
    void searchStudent() {
        int roll;
        cout << "\nEnter Roll Number to Search: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.rollNo == roll) {
                cout << "\nStudent Found!\n";
                s.display();
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }

    // Update Student
    void updateStudent() {
        int roll;
        cout << "\nEnter Roll Number to Update: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.rollNo == roll) {
                cout << "Enter New Marks: ";
                cin >> s.marks;

                cout << "\nStudent Updated Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }

    // Delete Student
    void deleteStudent() {
        int roll;
        cout << "\nEnter Roll Number to Delete: ";
        cin >> roll;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].rollNo == roll) {
                students.erase(students.begin() + i);
                cout << "\nStudent Deleted Successfully!\n";
                return;
            }
        }

        cout << "\nStudent Not Found!\n";
    }
};

// Main Function
int main() {
    StudentManagement sm;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sm.addStudent();
                break;

            case 2:
                sm.displayStudents();
                break;

            case 3:
                sm.searchStudent();
                break;

            case 4:
                sm.updateStudent();
                break;

            case 5:
                sm.deleteStudent();
                break;

            case 6:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
