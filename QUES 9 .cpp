
#include <iostream>
#include <exception>
using namespace std;

// Base Custom Exception
class BankingException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Exception Occurred!";
    }
};

// Insufficient Balance Exception
class InsufficientBalance : public BankingException {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient Balance!";
    }
};

// Invalid Amount Exception
class InvalidAmount : public BankingException {
public:
    const char* what() const noexcept override {
        return "Error: Invalid Transaction Amount!";
    }
};

// Bank Account Class
class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {

        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientBalance();
        }

        balance -= amount;

        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {

    BankAccount account(5000);

    try {
        double amount;

        cout << "Current Balance: 5000" << endl;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        account.withdraw(amount);
    }

    catch (InvalidAmount &e) {
        cout << e.what() << endl;
    }

    catch (InsufficientBalance &e) {
        cout << e.what() << endl;
    }

    catch (BankingException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
