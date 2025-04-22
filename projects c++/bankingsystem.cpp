#include <iostream>
#include <vector>
using namespace std;


class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
private:
    double balance;
public:
    BankAccount(int accNo, string name, double bal)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    virtual ~BankAccount() {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " successfully.\n";
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " successfully.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << "\n"
             << "Account Holder: " << accountHolderName << "\n"
             << "Balance: $" << balance << "\n";
    }

    virtual void calculateInterest() const {} 
};


class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() const override {
        cout << "Savings Interest: $" << getBalance() * interestRate / 100 << "\n";
    }
};


class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;
public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount > getBalance() + overdraftLimit) {
            cout << "Withdrawal exceeds overdraft limit!\n";
        } else {
            BankAccount::withdraw(amount);
        }
    }

    void checkOverdraft() const {
        cout << "Overdraft Limit: $" << overdraftLimit << "\n";
    }
};


class FixedDepositAccount : public BankAccount {
private:
    int term; 
    double interestRate = 7.0; 
public:
    FixedDepositAccount(int accNo, string name, double bal, int termMonths)
        : BankAccount(accNo, name, bal), term(termMonths) {}

    void calculateInterest() const override {
        double interest = getBalance() * interestRate / 100 * (term / 12.0);
        cout << "Fixed Deposit Interest for " << term << " months: $" << interest << "\n";
    }
};


void showMenu() {
    cout << "\n--- Bank Account Management System ---\n";
    cout << "1. Display Account Info\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Calculate Interest\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<BankAccount*> accounts;

   
    accounts.push_back(new SavingsAccount(1001, "Alice", 5000.0, 3.5));
    accounts.push_back(new CheckingAccount(1002, "Bob", 3000.0, 1000.0));
    accounts.push_back(new FixedDepositAccount(1003, "Charlie", 10000.0, 12));

    int choice, index;
    double amount;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 5) break;

        cout << "Select Account (0: Savings, 1: Checking, 2: Fixed Deposit): ";
        cin >> index;

        if (index < 0 || index >= accounts.size()) {
            cout << "Invalid account selection.\n";
            continue;
        }

        switch (choice) {
            case 1:
                accounts[index]->displayAccountInfo();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;
                accounts[index]->deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                accounts[index]->withdraw(amount);
                break;
            case 4:
                accounts[index]->calculateInterest();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

  
    for (auto acc : accounts) {
        delete acc;
    }

    cout << "Thank you for using our system!\n";
    return 0;
}