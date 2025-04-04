// Railway Reservation System.......


#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }
    Train(int tNo, const char *tName, const char *src, const char *dest, const char *tTime) {
        trainNumber = tNo;
        strcpy(trainName, tName);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, tTime);
        trainCount++;
    }
    ~Train() {
        trainCount--;
    }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber() const { return trainNumber; }
    static int getTrainCount() { return trainCount; }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() { totalTrains = 0; }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train added successfully!\n";
        } else {
            cout << "Cannot add more trains!\n";
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records found!\n";
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            cout << "Train " << (i + 1) << " details:" << endl;
            trains[i].displayTrainDetails();
            cout << "-----------------------\n";
        }
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "Train found:\n";
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << " not found!\n";
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            int trainNo;
            cout << "Enter Train Number to search: ";
            cin >> trainNo;
            system.searchTrainByNumber(trainNo);
            break;
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
