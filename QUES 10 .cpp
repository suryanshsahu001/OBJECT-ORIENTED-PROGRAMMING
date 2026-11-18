
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {

    Student s;

    // Open CSV file for reading and writing
    fstream file("students.csv", ios::in | ios::out | ios::trunc);

    if (!file) {
        cout << "File opening failed!";
        return 1;
    }

    // Write student records
    cout << "--- Enter Student Records ---\n";

    file << "RollNo,Name,Marks\n";

    for (int i = 0; i < 3; i++) {

        cout << "\nEnter Roll Number: ";
        cin >> s.rollNo;

        cout << "Enter Name: ";
        cin >> s.name;

        cout << "Enter Marks: ";
        cin >> s.marks;

        file << s.rollNo << "," << s.name << "," << s.marks << "\n";
    }

    // tellp() - Get current writing position
    cout << "\nWriting Position: " << file.tellp() << endl;

    // seekp() - Move writing pointer to end
    file.seekp(0, ios::end);

    cout << "Position after seekp(): " << file.tellp() << endl;

    file.flush();

    // seekg() - Move reading pointer to beginning
    file.seekg(0, ios::beg);

    cout << "\nReading Position: " << file.tellg() << endl;

    // Read student records
    cout << "\n--- Student Records from CSV File ---\n";

    string line;

    getline(file, line); // Skip CSV heading

    while (getline(file, line)) {

        stringstream ss(line);

        string roll, name, marks;

        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, marks, ',');

        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;

        // tellg() - Get current reading position
        cout << "Reading Position: " << file.tellg() << endl;
    }

    file.close();

    return 0;
}
