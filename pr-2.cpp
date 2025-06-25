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
    // Default constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized constructor
    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train() {
        trainCount--;
    }

    // Getters and Setters
    void setTrainNumber(int number) { trainNumber = number; }
    int getTrainNumber() const { return trainNumber; }

    void setTrainName(const char* name) { strcpy(trainName, name); }
    const char* getTrainName() const { return trainName; }

    void setSource(const char* src) { strcpy(source, src); }
    const char* getSource() const { return source; }

    void setDestination(const char* dest) { strcpy(destination, dest); }
    const char* getDestination() const { return destination; }

    void setTrainTime(const char* time) { strcpy(trainTime, time); }
    const char* getTrainTime() const { return trainTime; }

    // Input details
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // Flush newline
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display train details
    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    // Static method to get train count
    static int getTrainCount() {
        return trainCount;
    }
};

// Initialize static member
int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train storage is full!" << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available!" << endl;
        } else {
            for (int i = 0; i < totalTrains; ++i) {
                cout << "Train " << i + 1 << " details:" << endl;
                trains[i].displayTrainDetails();
                cout << endl;
            }
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; ++i) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};

int main() {
    RailwaySystem rs;
    int choice;

    do {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.addTrain();
                break;
            case 2:
                rs.displayAllTrains();
                break;
            case 3: {
                int number;
                cout << "Enter Train Number to search: ";
                cin >> number;
                rs.searchTrainByNumber(number);
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
