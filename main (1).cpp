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

        string in;
        //checks option does case statement
        switch (opt)
        {
        case '1':

            cout << "Create Reservation" << endl;
            cout << "------------------------" << endl;
            cout << "Enter First Name : ";
            cin >> in;
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