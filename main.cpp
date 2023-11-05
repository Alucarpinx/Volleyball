#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
//#include <cstdlib>
#include <string>

using namespace std;

void main() {

    char opt;

    //do while not 9 
    do {
        cout << "Please choose a option 1 - 4" << endl << endl;
        cout << " 1. reservation" << endl;
        cout << " 2. Vehicles" << endl;
        cout << " 3. Credits" << endl;
        cout << " 4. Done" << endl;
        cout << " Enter Option: ";
        cin >> opt;

        string in;
        //checks option does case statement
        switch (opt)
        {
        case '1':

            cout << "Reservation Menu" << endl;
            cout << "------------------------" << endl;
            cout << "Enter First Name : ";
            cin >> in;
            break;
        case '2':
            // displays a line choosen
            cout << "Vehicles Menu" << endl;
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
            cout << "Credit Menu" << endl;
            cout << "------------------------" << endl;
            cin >> in;

            break;

        case '4':
            //ends program
            cout << "  Option 4: Quitting Program.......";
            break;
        default:
            //defualt 
            cout << "Invalid choice. Please enter a number from 1 - 4";
        }
    } while (opt != '4');



}