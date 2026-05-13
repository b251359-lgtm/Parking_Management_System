#include <iostream>
#include <string>
using namespace std;

class ParkingSystem {
private:
    int totalSlots;
    int occupiedSlots;
    string vehicleNumbers[100];

public:

    ParkingSystem(int slots) {
        totalSlots = slots;
        occupiedSlots = 0;
    }

    void parkVehicle() {

        if (occupiedSlots >= totalSlots) {
            cout << "\nParking Full!\n";
            return;
        }

        string vehicleNo;

        cout << "\nEnter Vehicle Number: ";
        cin >> vehicleNo;

        vehicleNumbers[occupiedSlots] = vehicleNo;
        occupiedSlots++;

        cout << "Vehicle Parked Successfully!\n";
        cout << "Allocated Slot: " << occupiedSlots << endl;
    }

    void removeVehicle() {

        if (occupiedSlots == 0) {
            cout << "\nParking Empty!\n";
            return;
        }

        string vehicleNo;
        bool found = false;

        cout << "\nEnter Vehicle Number to Remove: ";
        cin >> vehicleNo;

        for (int i = 0; i < occupiedSlots; i++) {

            if (vehicleNumbers[i] == vehicleNo) {

                found = true;

                for (int j = i; j < occupiedSlots - 1; j++) {
                    vehicleNumbers[j] = vehicleNumbers[j + 1];
                }

                occupiedSlots--;

                cout << "Vehicle Removed Successfully!\n";
                break;
            }
        }

        if (!found) {
            cout << "Vehicle Not Found!\n";
        }
    }

    void displayStatus() {

        cout << "\n===== Parking Status =====\n";

        cout << "Total Slots     : " << totalSlots << endl;
        cout << "Occupied Slots  : " << occupiedSlots << endl;
        cout << "Available Slots : "
             << totalSlots - occupiedSlots << endl;

        cout << "\nParked Vehicles:\n";

        if (occupiedSlots == 0) {
            cout << "No Vehicles Parked\n";
        }
        else {

            for (int i = 0; i < occupiedSlots; i++) {
                cout << i + 1 << ". "
                     << vehicleNumbers[i] << endl;
            }
        }
    }
};

int main() {

    int slots;

    cout << "===== Smart Parking Management System =====\n";

    cout << "Enter Total Parking Slots: ";
    cin >> slots;

    ParkingSystem parking(slots);

    int choice;

    do {

        cout << "\n===== MENU =====\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Parking Status\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                parking.parkVehicle();
                break;

            case 2:
                parking.removeVehicle();
                break;

            case 3:
                parking.displayStatus();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}