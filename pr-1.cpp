#include <iostream>
#include <iomanip>
using namespace std;

class TimeConverter {
public:
    // Convert seconds to HH:MM:SS
    void convertToHHMMSS(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }

    // Convert HH:MM:SS to total seconds
    void convertToSeconds(int hours, int minutes, int seconds) {
        int total = hours * 3600 + minutes * 60 + seconds;
        cout << "Total seconds: " << total << endl;
    }
};

int main() {
    TimeConverter tc;
    int choice;
    cout << "1. Convert seconds to HH:MM:SS" << endl;
    cout << "2. Convert HH:MM:SS to seconds" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int totalSeconds;
        cout << "Enter total seconds: ";
        cin >> totalSeconds;
        tc.convertToHHMMSS(totalSeconds);
    } else if (choice == 2) {
        int h, m, s;
        cout << "Enter hours: ";
        cin >> h;
        cout << "Enter minutes: ";
        cin >> m;
        cout << "Enter seconds: ";
        cin >> s;
        tc.convertToSeconds(h, m, s);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
