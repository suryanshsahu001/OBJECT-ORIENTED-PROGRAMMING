
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    int marks;
};

int main() {

    // 1. Using vector to store student details
    vector<Student> students = {
        {101, "Rahul", 85},
        {102, "Aman", 72},
        {103, "Priya", 95},
        {104, "Sneha", 60},
        {105, "Rohan", 78}
    };

    // 2. Using map to store roll number and student name
    map<int, string> studentMap;

    for (int i = 0; i < students.size(); i++) {
        studentMap[students[i].rollNo] = students[i].name;
    }

    // 3. Using unordered_map to store name and marks
    unordered_map<string, int> marksMap;

    for (int i = 0; i < students.size(); i++) {
        marksMap[students[i].name] = students[i].marks;
    }

    // Display student records
    cout << "\n--- Student Records ---\n";

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].rollNo << " "
             << students[i].name << " "
             << students[i].marks << endl;
    }

    // 4. Sort students according to marks
    sort(students.begin(), students.end(),
         [](Student a, Student b) {
             return a.marks > b.marks;
         });

    cout << "\n--- Students Sorted by Marks ---\n";

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " - "
             << students[i].marks << endl;
    }

    // 5. Using find_if to find a student
    auto it = find_if(students.begin(), students.end(),
        [](Student s) {
            return s.name == "Priya";
        });

    cout << "\n--- Searching Student ---\n";

    if (it != students.end()) {
        cout << "Student Found: " << it->name
             << ", Marks: " << it->marks << endl;
    } else {
        cout << "Student Not Found!" << endl;
    }

    // 6. Using transform to add 5 grace marks
    vector<int> updatedMarks(students.size());

    transform(students.begin(), students.end(),
              updatedMarks.begin(),
              [](Student s) {
                  return s.marks + 5;
              });

    cout << "\n--- Marks After Adding 5 Grace Marks ---\n";

    for (int i = 0; i < updatedMarks.size(); i++) {
        cout << students[i].name << " - "
             << updatedMarks[i] << endl;
    }

    return 0;
}
