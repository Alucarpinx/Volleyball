#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "reservation.h"
#include "team.h"
#include "cars.h"

using namespace std;

vector <team_mem> non_Driver;
vector <reservation> reservations;// new standalone class for reservations

void reservation :: reserveReservation(string firstName) {
    bool validPass = false;
    int index = -1;
    for (int j = 0; j < non_Driver.size(); j++) {
        if (non_Driver[j].first_name == firstName) {
            validPass = true;
        }index = j;
    }
    if (!validPass) {
        cout << firstName << " was not found on the list\n";
        return;
    }
    int credits = non_Driver[index].credits;
    cout << firstName << " has " << credits << " credits available\m";
    if (credits == 0) {
        cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
        return;
    }
    // display the cars and seats

    string vehicle;
    int seatSelect;
    cout << "Select a specific vehicle\n";
    cin >> vehicle;
    cout << "Select speficic seat\n";
    cin >> seatSelect;
    //we can create a new vector with firstname and pin for reservations
    bool seatAvailable;
    int requiredCredits;

    if (seatAvailable && requiredCredits) {
    
    }
}

void reservation::modifyReservation() {
    string firstName;
    int PIN; // or int idk we can use a 2 digit pin 
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "\nEnter the reservation PIN: ";
    cin >> PIN;

    bool reservationFound = false;
    int index = -1;
    for (int i = 0; i < non_Driver.size(); i++) {
        if ((reservations[i].first_name == firstName) && (reservations[i].PIN == PIN)) {
            reservationFound = true;
            index = i;
            break;
        }
    }
    if (!reservationFound) {
        cout << "\nReservation not found.Name and/or PIN may not match. Please double check\n";
        return;
    }
    // display the cars and seats

    string vehicle;
    int seatSelect;
    cout << "Select a specific vehicle\n";
    cin >> vehicle;
    cout << "Select speficic seat\n";
    cin >> seatSelect;

    bool seatAvailable;
    int requiredCredits;

    if (seatAvailable && requiredCredits) {

    }
    //delete old reservation create new one

    cout << "Reservation has been modified\n";
}

void reservation::deleteReservation() {
    string firstName;
    int PIN; // or int idk we can use a 2 digit pin 
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "\nEnter the reservation PIN: ";
    cin >> PIN;

    bool reservationFound = false;
    int index = -1;
    for (int i = 0; i < non_Driver.size(); i++) {
        if (reservations[i].first_name == firstName && reservations[i].PIN == PIN) {
            reservationFound = true;
            index = i;
            break;
        }
    }
    if (!reservationFound) {
        cout << "\nReservation not found.Name and/or PIN may not match. Please double check\n";
        return;
    }
    reservations.erase(reservations.begin() + index);
    cout << "Reservation deleted\n";
}

void reservation::displayVehicles() {

}

void reservation::printVehicle() {
    string vehicle;
    cout << "Enter vehicle type: ";
    cin >> vehicle;
    ofstream outputFile(vehicle + ".txt");
    if (!outputFile) {
        cout << "\nError creating output file\n";
        return;
    }
    for (int h = 0; h < reservations.size(); h++) {
        if (reservations.vehicle == vehicle) {
            cout << "Passenger : " << reservations.first_name << ", Seat: " << reservations.seat << endl;
            outputFile << "Passenger : " << reservations.first_name << ", Seat: " << reservations.seat << endl;
        }
    }
    outputfile.close();
    cout << "Vehicle assignments printed to file " << vehicle << ".txt" << endl;
}

const string hardPassword = "passWORD";

void reservation::printReservations() {
    string password;
    cout << "Enter admin password: ";
    cin >> password;

    if (password == hardPassword) {
        ofstream outputFile("reservations.txt");
        if (!outputFile) {
            cout << "Error creating output file.\n";
            return
        }
        for (int h = 0; h < reservatiom.size(); h++) {
                outputFile << "Vehicle : " << reservation.vehicle << endl;
                outputFile << "driver : " << reservation.DriverName << endl;
                if (resevation.seat != -1) {
                    outputFile << "Passenger: " << reservation.passenger << ", Seat " << reservation.seat << endl;
                }
                else {
                    outputFile << "Passenger unassigned\n";
                }
            }
        outputFile.close();
        cout << "Reservations printed to reservations.txt\n";
    }
    else {
        cout << "\nIncorrect admin password.\n";
    }
}



//void reservation::reserveSeat(string firstName) {
//    string firstName;
//    cout << "Passenger's first name: ";
//    cin >> firstName;
//    //loop to check vector for first name
//    vector <team_mem> non_Driver;
//
//    for (const string& Name : non_Driver) {
//        if (Name == firstName) {
//            int credits = getCredits(Name);
//            cout << firstName << " has " << credits << ".\n";
//            if (credits == '0') {
//                cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
//                break;
//            }
//        }
//        else {
//            cout << "The name " << firstName << " not found on list.\n";
//            break;
//        }
        //display car 
        /*
        1: passenger
        2:middle back
        3:left back
        4:right back
        */
        break;
    }

}
//	vector<team_mem> mum_drive 
//}