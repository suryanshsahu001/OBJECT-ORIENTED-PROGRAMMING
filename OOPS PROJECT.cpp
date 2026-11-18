
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// ======================================
// 1. ABSTRACTION
// ======================================

class User {
protected:
    string name;
    string email;

public:
    virtual void displayDetails() const = 0;

    virtual ~User() {}
};

// ======================================
// 2. INHERITANCE
// Participant inherits User
// ======================================

class Participant : public User {
private:
    int id;
    string eventName;

public:

    // Constructor
    Participant(int i, string n, string e, string event) {
        id = i;
        name = n;
        email = e;
        eventName = event;
    }

    // Getter
    int getID() const {
        return id;
    }

    string getEmail() const {
        return email;
    }

    // ==================================
    // 3. POLYMORPHISM
    // Function overriding
    // ==================================

    void displayDetails() const override {
        cout << "\nRegistration ID: " << id;
        cout << "\nName: " << name;
        cout << "\nEmail: " << email;
        cout << "\nEvent: " << eventName << endl;
    }
};

// ======================================
// 4. ENCAPSULATION
// ======================================

class EventRegistration {
private:
    vector<Participant> participants;

    unordered_set<string> registeredEmails;

    int nextID;

public:

    // Constructor
    EventRegistration() {
        nextID = 1001;
    }

    // Register Participant
    void registerParticipant() {

        string name, email, eventName;

        cout << "\nEnter Participant Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        // Duplicate email checking
        if (registeredEmails.find(email)
            != registeredEmails.end()) {

            cout << "\nEmail Already Registered!\n";
            return;
        }

        cout << "Enter Event Name: ";
        getline(cin, eventName);

        Participant p(nextID++, name, email, eventName);

        participants.push_back(p);

        registeredEmails.insert(email);

        cout << "\nRegistration Successful!";
        cout << "\nYour Registration ID: "
             << p.getID() << endl;
    }

    // Display All Participants
    void displayParticipants() {

        if (participants.empty()) {
            cout << "\nNo Registrations Found.\n";
            return;
        }

        cout << "\n===== REGISTERED PARTICIPANTS =====\n";

        for (const Participant& p : participants) {
            p.displayDetails();
        }
    }

    // Search Participant - Linear Search
    void searchParticipant() {

        int searchID;

        cout << "\nEnter Registration ID: ";
        cin >> searchID;
        cin.ignore();

        bool found = false;

        for (const Participant& p : participants) {

            if (p.getID() == searchID) {

                cout << "\nParticipant Found!\n";

                p.displayDetails();

                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nParticipant Not Found!\n";
        }
    }
};

// ======================================
// MAIN FUNCTION
// ======================================

int main() {

    EventRegistration system;

    int choice;

    do {

        cout << "\n========== EVENT REGISTRATION SYSTEM ==========\n";

        cout << "1. Register Participant\n";
        cout << "2. Display All Participants\n";
        cout << "3. Search Participant\n";
        cout << "0. Exit\n";

        cout << "\nEnter Your Choice: ";

        if (!(cin >> choice)) {

            cout << "Invalid Input!\n";

            cin.clear();
            cin.ignore(10000, '\n');

            continue;
        }

        cin.ignore();

        switch (choice) {

            case 1:
                system.registerParticipant();
                break;

            case 2:
                system.displayParticipants();
                break;

            case 3:
                system.searchParticipant();
                break;

            case 0:
                cout << "\nThank You for Using the System!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}
