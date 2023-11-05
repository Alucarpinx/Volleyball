#include "dodgeball.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>	
#include <string>

using namespace std;

//Open the text file
ifstream Opendodgeball()
{
	string inFileName = "dodgeball_team.txt";
	ifstream temp;

	temp.open(inFileName.c_str());

	//check if it was open
	if (!temp.is_open()) {
		cout << "\nUnsuccessfully... Program Terminated\n" << endl;
		exit(1);
	}
	return (temp);
}
int main()
{
	//initulize file and assign it
	ifstream inFile;
	inFile = Opendodgeball();

	//vetors for song and strings for NAME ARTIST AND URL
	vector<team_mem> nun_Drive;
	string NunDriver_first;
	string NunDriver_last;
	int credits_;

	vector<team_mem> Driver;
	string Driver_first;
	string Driver_last;

	team_mem tempmem;
	team_mem tempName;

		for (int i = 0; i < 9; i++) {
			inFile >> Driver_first >> Driver_last;
			team_mem tempmem(Driver_first, Driver_last, -1);
			Driver.push_back(tempmem);
		}
		for (int i = 0; i < 24; i++) {
			inFile >> Driver_first >> Driver_last >> credits_;
			team_mem tempName(Driver_first, Driver_last, credits_);
			nun_Drive.push_back(tempName);

    char opt;

    //do while not 9 
    do {
        cout << "Please choose a option 1 - 4" << endl << endl;
        cout << " 1. Create Reservation" << endl;
        cout << " 2. Modify Reservation" << endl;
        cout << " 3. Delete reservation" << endl;
        cout << " 4. Display vehicles" << endl;
        cout << " 5. Print vehicle Assignments" << endl;
        cout << " 6. Print Reservations" << endl;
        cout << " Enter Option: ";
        cin >> opt;

        string in_;
        //checks option does case statement
        switch (opt)
        {
        case '1':

            cout << "Create Reservation" << endl;
            cout << "------------------------" << endl;
            reserveReservation();
			void displayVehicles();
			}
   	    }
            break;
        case '2':
            // displays a line choosen
            cout << "Modify Reservation" << endl;
            cout << "------------------------" << endl;
            cout << "Truck" << "   Sedan" << "    Compact" << endl;
            cout << "Enter Type of Vehicles : ";
            cin >> in;
            if (in == "Truck")
            {

            }
            else if (in == "Sedan")
            {

            }
            else if (in == "Compact")
            {

            }
            else
                cout << "Invalid Car. Enter ""Truck"" ""Sedan"" ""Compact""." << endl;
            break;

        case '3':
            //displays all lines
            cout << "Delete reservation" << endl;
            cout << "------------------------" << endl;
            cin >> in;

            break;
        case '4':
            //ends program
            cout << "Display Vehicles";
            break;
        case '5':
            //ends program
            cout << "Print Vehicle Assignments";
            break;
        case '6':
            //ends program
            cout << "Option 4: Quitting Program.......";
            break;
        default:
            //defualt 
            cout << "Invalid choice. Please enter a number from 1 - 6";
        }
    } while (opt != '6');



}