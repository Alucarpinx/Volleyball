#include "dodgeball.h"
#include "Pickup.h"
#include "Compact.h"
#include "Sedan.h"
#include "reservation.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <set>

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

    // reservation reserved[24];
    Pickup Truck[3];// creates three objects of the pickup truck class
    Compact Pact[3];
    Sedan Dan[3];
    //truck[index].setColor
    //initulize file and assign it
    ifstream inFile;
    inFile = Opendodgeball();

    //vetors for song and strings for NAME ARTIST AND URL
    vector<team_mem> nun_Driver;
    string first_name;
    string NunDriver_last;
    int credits_;

    vector<team_mem> Driver;
    string Driver_first;
    string Driver_last;

    vector<reservation> reserved;

    reservation tempres;
    team_mem tempmem;
    team_mem tempName;


    for (int i = 0; i < 9; i++) {
        inFile >> Driver_first >> Driver_last;
        team_mem tempmem(Driver_first, Driver_last, -1);
        Driver.push_back(tempmem);
    }
    Truck[0].setDriver("Pat");
    Truck[0].setColor("Purple");
    Truck[1].setDriver("Jane");
    Truck[1].setColor("Green");
    Truck[2].setDriver("Tim");
    Truck[2].setColor("Black");

    Pact[0].setDriver("Ben");
    Pact[0].setColor("Red");
    Pact[1].setDriver("Art");
    Pact[1].setColor("Blue");
    Pact[2].setDriver("Ann");
    Pact[2].setColor("Yellow");

    Dan[0].setDriver("Grace");
    Dan[0].setColor("Blue");
    Dan[1].setDriver("Lary");
    Dan[1].setColor("Black");
    Dan[2].setDriver("Jessie");
    Dan[2].setColor("Green");

    bool seat_ = false;
    bool color_t = false;

    for (int i = 0; i < 24; i++) {
        inFile >> first_name >> Driver_last >> credits_;
        team_mem tempName(first_name, NunDriver_last, credits_);
        nun_Driver.push_back(tempName);
    }
    int opt;

    //do while not 9 
    do {
        cout << "Please choose a option 1 - 6" << endl << endl;
        cout << " 1. Create Reservation" << endl;
        cout << " 2. Modify Reservation" << endl;
        cout << " 3. Delete reservation" << endl;
        cout << " 4. Display vehicles" << endl;
        cout << " 5. Print vehicle Assignments" << endl;
        cout << " 6. Print Reservations" << endl;
        cout << " Enter Option: ";
        cin >> opt;

        //checks option does case statement
        switch (opt)
        {
        case 1: {

            cout << "Create Reservation" << endl;
            cout << "------------------------" << endl;
            bool validPass = false;
            int index = 99;

            string firstName;
            cout << "Enter First Name: ";
            cin >> firstName;
            for (int j = 0; j < nun_Driver.size(); j++) {
                if (nun_Driver[j].getName() == firstName) {
                    validPass = true;
                    index = j;
                }
            }
            if (!validPass) {
                cout << firstName << " was not found on the list\n";
                break;
            }
            int credits = nun_Driver[index].getCredit();
            cout << firstName << " has " << credits << " credits available\n";
            if (credits == 0) {
                cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
                break;
            }
            //string res_ = "notdone";
            // do {
                // display the cars and seats
            cout << "\nDisplay Vehicles\n";

            for (int i = 0; i < 3; i++)
            {
                Truck[i].displayPickup();
            }
            for (int i = 0; i < 3; i++)
            {
                Pact[i].displayCompact();
            }
            for (int i = 0; i < 3; i++)
            {
                Dan[i].displaySedan();
            }

            int vehicle;
            string vehicleType;
            int seatSelect;
            bool Confirm = false;
            string seat;
            int color_num = 0;
            bool getOut = false;
            string color_ = "notdone";
            cout << "\nSelect a specific vehicle\n";
            cout << "\n1.Truck" << "   2.Sedan" << "    3.Compact" << endl;
            cout << "Enter Number: " << endl;
            cin >> vehicle;
            if (vehicle == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    Truck[i].displayPickup();
                }
                color_t = false;
                do {
                    seat_ = false;
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Purple] [2.Green] [3.Black]" << endl;
                    cin >> color_num;
                    //PURPLE
                    if (color_num == 1) {
                        if (Truck[0].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[0].getFrontCredit() <= credits) {
                                        Truck[0].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }
                                }
                                else {
                                    cout << "\nseat not available. No space in this vehicle\n";
                                }
                                //seat_ = true;
                            } while (getOut == false);

                            color_ = "Purple";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color or vehicle\n";
                            //color_ = "Done";
                        }


                    }
                    //GREEN
                    else if (color_num == 2) {
                        if (Truck[1].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[1].getFrontCredit() <= credits) {
                                        Truck[1].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }

                                }
                                else {
                                    cout << "\n Please choose a valid seat option\n";
                                }
                            } while (getOut == false);
                            color_ = "Green";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color or vehicle\n";
                            //color_ = "Done";

                        }

                    }
                    //BLACK
                    else if (color_num == 3) {
                        if (Truck[2].getFront() == "X") {
                            do {
                                cout << "Select speficic seat [1.Front] " << endl;
                                cout << "Enter: ";
                                cin >> seatSelect;
                                if (seatSelect == 1) {
                                    if (Truck[2].getFrontCredit() <= credits) {
                                        Truck[2].setFront(firstName);
                                        vehicleType = "Pickup";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                        getOut = true;
                                    }
                                }
                                else {
                                    cout << "\n Please choose a valid seat option\n";
                                }
                            } while (getOut == false);
                            color_ = "Black";
                            color_t = true;
                        }
                        else {
                            cout << "\nNo seats available. Please choose a different color\n";
                            //color_ = "Done";
                        }
                    }
                    else {
                        cout << "invalid Color" << endl;
                    }
                    /*if (Truck[0].getFront() != "X" && Truck[1].getFront() == "X" && Truck[2].getFront() == "X")
                    {
                        cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                        color_t = true;
                    }*/
                } while (color_t == false);

            }





            else if (vehicle == 2)
            {
                for (int i = 0; i < 3; i++)
                {
                    Dan[i].displaySedan();
                }
                do {
                    seat = "notdone";
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Blue] [2.Black] [3.Green] " << endl;
                    cin >> color_num;

                    //blue
                    if (color_num == 1) {
                        Dan[0].displaySedan();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Dan[0].getFront() == "X") {
                                    if (Dan[0].getFrontCredit() <= credits) {
                                        Dan[0].setFront(firstName);
                                        vehicleType = "Sedan";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Dan[0].getBackMid() == "X") {
                                    if (Dan[0].getBackMidCredit() <= credits) {
                                        Dan[0].setBackMid(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackMid";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Dan[0].getBackLeft() == "X") {
                                    if (Dan[0].getBackLeftCredit() <= credits) {
                                        Dan[0].setBackLeft(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                if (Dan[0].getBackRight() == "X") {
                                    if (Dan[0].getBackRightCredit() <= credits) {
                                        Dan[0].setBackRight(firstName);
                                        vehicleType = "Sedan";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 5) {
                                getOut = true;
                            }
                        } while (getOut == false);
                    }
                    color_ = "Blue";
                    color_t = true;
                } while (color_t == false);
            }









            //BLACK
            else if (color_num == 2) {
                Dan[1].displaySedan();
                do {
                    cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                    cout << "Enter: ";
                    cin >> seatSelect;
                    if (seatSelect == 1) {
                        if (Dan[1].getFront() == "X") {
                            if (Dan[1].getFrontCredit() <= credits) {
                                Dan[1].setFront(firstName);
                                vehicleType = "Sedan";
                                seat = "Front";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }

                    }
                    else if (seatSelect == 2) {
                        if (Dan[1].getBackMid() == "X") {
                            if (Dan[1].getBackMidCredit() <= credits) {
                                Dan[1].setBackMid(firstName);
                                vehicleType = "Sedan";
                                seat = "BackMid";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }
                    }
                    else if (seatSelect == 3) {
                        if (Dan[1].getBackLeft() == "X") {
                            if (Dan[1].getBackLeftCredit() <= credits) {
                                Dan[1].setBackLeft(firstName);
                                vehicleType = "Sedan";
                                seat = "BackLeft";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }
                    }
                    else if (seatSelect == 4) {
                        if (Dan[1].getBackRight() == "X") {
                            if (Dan[1].getBackRightCredit() <= credits) {
                                Dan[1].setBackRight(firstName);
                                vehicleType = "Sedan";
                                seat = "BackRight";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }
                    }
                    else if (seatSelect == 5) {
                        getOut = true;
                    }
                } while (getOut == false);

                color_ = "Black";
                color_t = true;

            }





            //GREEN
            else if (color_num == 3) {
                Dan[2].displaySedan();
                do {
                    cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                    cout << "Enter: ";
                    cin >> seatSelect;
                    if (seatSelect == 1) {
                        if (Dan[2].getFront() == "X") {
                            if (Dan[2].getFrontCredit() <= credits) {
                                Dan[2].setFront(firstName);
                                vehicleType = "Sedan";
                                seat = "Front";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }

                    }
                    else if (seatSelect == 2) {
                        if (Dan[2].getBackMid() == "X") {
                            if (Dan[2].getBackMidCredit() <= credits) {
                                Dan[2].setBackMid(firstName);
                                vehicleType = "Sedan";
                                seat = "BackMid";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }
                    }
                    else if (seatSelect == 3) {
                        if (Dan[2].getBackLeft() == "X") {
                            if (Dan[2].getBackLeftCredit() <= credits) {
                                Dan[2].setBackLeft(firstName);
                                vehicleType = "Sedan";
                                seat = "BackLeft";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat,color\n";

                        }
                    }
                    else if (seatSelect == 4) {
                        if (Dan[2].getBackRight() == "X") {
                            if (Dan[2].getBackRightCredit() <= credits) {
                                Dan[2].setBackRight(firstName);
                                vehicleType = "Sedan";
                                seat = "BackRight";
                                seat_ = true;
                                getOut = true;
                            }
                            else {
                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                seat_ = false;
                            }
                        }
                        else {
                            cout << "\nSeat not available. Please choose a different seat\n";

                        }
                    }
                    else if (seatSelect == 5) {
                        getOut = true;
                    }
                    else {
                        cout << "invalid Color" << endl;
                    }
                } while (getOut == false);
                color_ = "Green";
                color_t = true;

                // checks if all cars are taken
                /*if (Dan[0].getFront() != "X" && Dan[1].getFront() == "X" && Dan[2].getFront() == "X" && Dan[0].getBackMid() == "X" && Dan[1].getBackMid() == "X" && Dan[2].getBackMid() == "X" && Dan[0].getBackLeft() == "X" && Dan[1].getBackLeft() == "X" && Dan[3].getBackLeft() == "X" && Dan[0].getBackRight() == "X" && Dan[1].getBackRight() == "X" && Dan[3].getBackRight() == "X")
                {
                    cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                    color_t = true;
                }*/
            }
            //while (color_t == false);























            else if (vehicle == 3)
            {
                for (int i = 0; i < 3; i++)
                {
                    Pact[i].displayCompact();
                }
                do {
                    seat = "notdone";
                    cout << "Select a specific Color\n";
                    cout << "Select speficic color [1.Red] [2.Blue] [3.Yellow]" << endl;
                    cin >> color_num;

                    //RED
                    if (color_num == 1) {
                        Pact[0].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Pact[0].getFront() == "X") {
                                    if (Pact[0].getFrontCredit() <= credits) {
                                        Pact[0].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }

                            else if (seatSelect == 2) {
                                if (Pact[0].getBackLeft() == "X") {
                                    if (Pact[0].getBackLeftCredit() <= credits) {
                                        Pact[0].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[0].getBackRight() == "X") {
                                    if (Pact[0].getBackRightCredit() <= credits) {
                                        Pact[0].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);
                        color_ = "Red";
                        color_t = true;
                    }











                    //Blue
                    else if (color_num == 2) {
                        Pact[1].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == 1) {
                                if (Pact[1].getFront() == "X") {
                                    if (Pact[1].getFrontCredit() <= credits) {
                                        Pact[1].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }

                            else if (seatSelect == 2) {
                                if (Pact[1].getBackLeft() == "X") {
                                    if (Pact[1].getBackLeftCredit() <= credits) {
                                        Pact[1].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[1].getBackRight() == "X") {
                                    if (Pact[1].getBackRightCredit() <= credits) {
                                        Pact[1].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);

                        color_ = "Blue";
                        color_t = true;
                    }








                    //Yellow
                    else if (color_num == 3) {
                        Pact[2].displayCompact();
                        do {
                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                            cout << "Enter: ";
                            cin >> seatSelect;
                            if (seatSelect == '1') {
                                if (Pact[2].getFront() == "X") {
                                    if (Pact[2].getFrontCredit() <= credits) {
                                        Pact[2].setFront(firstName);
                                        vehicleType = "Compact";
                                        seat = "Front";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }

                            }
                            else if (seatSelect == 2) {
                                if (Pact[2].getBackLeft() == "X") {
                                    if (Pact[2].getBackLeftCredit() <= credits) {
                                        Pact[2].setBackLeft(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackLeft";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                }
                            }
                            else if (seatSelect == 3) {
                                if (Pact[2].getBackRight() == "X") {
                                    if (Pact[2].getBackRightCredit() <= credits) {
                                        Pact[2].setBackRight(firstName);
                                        vehicleType = "Compact";
                                        seat = "BackRight";
                                        seat_ = true;
                                        getOut = true;
                                    }
                                    else {
                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                        seat_ = false;
                                    }
                                }
                                else {
                                    cout << "\nSeat not available. Please choose a different seat\n";

                                }
                            }
                            else if (seatSelect == 4) {
                                getOut = true;
                            }
                        } while (getOut == false);

                        color_ = "Yellow";
                        color_t = true;
                    }

                    else {
                        cout << "invalid Color" << endl;
                    }
                    /*if ((Pact[0].getFront() != "X") && (Pact[1].getFront() == "X") && (Pact[2].getFront() == "X") && (Pact[0].getBackLeft() == "X") && (Pact[1].getBackLeft() == "X") && (Pact[3].getBackLeft() == "X") && (Pact[0].getBackRight() == "X") && (Pact[1].getBackRight() == "X") && (Pact[3].getBackRight() == "X"))
                    {
                        cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                        color_t = true;
                    }*/
                } while (color_t == false);
            }


            if (seat_ == true) {
                int num_pin = 26;
                int max = 99;
                int pin;

                vector<int> randNumber;
                srand(time(NULL));
                int nextRand;
                int current_size;
                set<int> pin_;

                while (pin_.size() < num_pin)
                {
                    nextRand = rand() % (max + 1);
                    current_size = pin_.size();
                    pin_.insert(nextRand);
                    if (current_size == pin_.size()) {
                    }
                    else {
                        randNumber.push_back(nextRand);
                    }
                }
                pin = nextRand;
                reservation tempres(firstName, vehicleType, color_, pin, seat);
                reserved.push_back(tempres);
                cout << "you have successfully made a reservation. Your Pin is :" << pin << endl;
            }
            else if (seat_ == false) {
                cout << "\nUnable to make reservation. Please Try Again.\n";
            }
            else {
                cout << "\nUnknown Issue. Please Try Again\n";
            }






            break; }
        case 2: {
            bool foundCheck = false;
            bool resChanged = false;
            string nameSer;
            int PINSer;
            cout << "Modify Reservation" << endl;
            cout << "------------------------" << endl;
            do {
                do {
                    cout << "\nWhat is the name used on the Reservation?: ";
                    cin >> nameSer;
                    cout << "\nWhat is the PIN for the Reservation?: ";
                    cin >> PINSer;
                    for (int k = 0; k < reserved.size(); ++k) {
                        if (reserved.at(k).getName() == nameSer && reserved.at(k).getPin() == PINSer) {
                            foundCheck = true;
                            cout << "\nServation Found. Deleting reservation...\n";
                            reserved.erase(reserved.begin() + k);
                            
                            cout << "\nReservation removed. Please make a new reservation.\n";
                            cout << "------------------------" << endl;
                            bool validPass = false;
                            int index = 99;

                            string firstName;
                            cout << "Enter First Name: ";
                            cin >> firstName;
                            for (int j = 0; j < nun_Driver.size(); j++) {
                                if (nun_Driver[j].getName() == firstName) {
                                    validPass = true;
                                    index = j;
                                }
                            }
                            if (!validPass) {
                                cout << firstName << " was not found on the list\n";
                                break;
                            }
                            int credits = nun_Driver[index].getCredit();
                            cout << firstName << " has " << credits << " credits available\n";
                            if (credits == 0) {
                                cout << firstName << " has zero credits. Unable to make reservation. Must provide their own transportation.\n";
                                break;
                            }
                            //string res_ = "notdone";
                            // do {
                                // display the cars and seats
                            cout << "\nDisplay Vehicles\n";

                            for (int i = 0; i < 3; i++)
                            {
                                Truck[i].displayPickup();
                            }
                            for (int i = 0; i < 3; i++)
                            {
                                Pact[i].displayCompact();
                            }
                            for (int i = 0; i < 3; i++)
                            {
                                Dan[i].displaySedan();
                            }

                            int vehicle;
                            string vehicleType;
                            int seatSelect;
                            bool Confirm = false;
                            string seat;
                            int color_num = 0;
                            bool getOut = false;
                            string color_ = "notdone";
                            cout << "\nSelect a specific vehicle\n";
                            cout << "\n1.Truck" << "   2.Sedan" << "    3.Compact" << endl;
                            cout << "Enter Number: " << endl;
                            cin >> vehicle;
                            if (vehicle == 1)
                            {
                                for (int i = 0; i < 3; i++)
                                {
                                    Truck[i].displayPickup();
                                }
                                color_t = false;
                                do {
                                    seat_ = false;
                                    cout << "Select a specific Color\n";
                                    cout << "Select speficic color [1.Purple] [2.Green] [3.Black]" << endl;
                                    cin >> color_num;
                                    //PURPLE
                                    if (color_num == 1) {
                                        if (Truck[0].getFront() == "X") {
                                            do {
                                                cout << "Select speficic seat [1.Front] " << endl;
                                                cout << "Enter: ";
                                                cin >> seatSelect;
                                                if (seatSelect == 1) {
                                                    if (Truck[0].getFrontCredit() <= credits) {
                                                        Truck[0].setFront(firstName);
                                                        vehicleType = "Pickup";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                        getOut = true;
                                                    }
                                                }
                                                else {
                                                    cout << "\nseat not available. No space in this vehicle\n";
                                                }
                                                //seat_ = true;
                                            } while (getOut == false);

                                            color_ = "Purple";
                                            color_t = true;
                                        }
                                        else {
                                            cout << "\nNo seats available. Please choose a different color or vehicle\n";
                                            //color_ = "Done";
                                        }


                                    }
                                    //GREEN
                                    else if (color_num == 2) {
                                        if (Truck[1].getFront() == "X") {
                                            do {
                                                cout << "Select speficic seat [1.Front] " << endl;
                                                cout << "Enter: ";
                                                cin >> seatSelect;
                                                if (seatSelect == 1) {
                                                    if (Truck[1].getFrontCredit() <= credits) {
                                                        Truck[1].setFront(firstName);
                                                        vehicleType = "Pickup";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                        getOut = true;
                                                    }

                                                }
                                                else {
                                                    cout << "\n Please choose a valid seat option\n";
                                                }
                                            } while (getOut == false);
                                            color_ = "Green";
                                            color_t = true;
                                        }
                                        else {
                                            cout << "\nNo seats available. Please choose a different color or vehicle\n";
                                            //color_ = "Done";

                                        }

                                    }
                                    //BLACK
                                    else if (color_num == 3) {
                                        if (Truck[2].getFront() == "X") {
                                            do {
                                                cout << "Select speficic seat [1.Front] " << endl;
                                                cout << "Enter: ";
                                                cin >> seatSelect;
                                                if (seatSelect == 1) {
                                                    if (Truck[2].getFrontCredit() <= credits) {
                                                        Truck[2].setFront(firstName);
                                                        vehicleType = "Pickup";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                        getOut = true;
                                                    }
                                                }
                                                else {
                                                    cout << "\n Please choose a valid seat option\n";
                                                }
                                            } while (getOut == false);
                                            color_ = "Black";
                                            color_t = true;
                                        }
                                        else {
                                            cout << "\nNo seats available. Please choose a different color\n";
                                            //color_ = "Done";
                                        }
                                    }
                                    else {
                                        cout << "invalid Color" << endl;
                                    }
                                    /*if (Truck[0].getFront() != "X" && Truck[1].getFront() == "X" && Truck[2].getFront() == "X")
                                    {
                                        cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                                        color_t = true;
                                    }*/
                                } while (color_t == false);

                            }





                            else if (vehicle == 2)
                            {
                                for (int i = 0; i < 3; i++)
                                {
                                    Dan[i].displaySedan();
                                }
                                do {
                                    seat = "notdone";
                                    cout << "Select a specific Color\n";
                                    cout << "Select speficic color [1.Blue] [2.Black] [3.Green] " << endl;
                                    cin >> color_num;

                                    //blue
                                    if (color_num == 1) {
                                        Dan[0].displaySedan();
                                        do {
                                            cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                                            cout << "Enter: ";
                                            cin >> seatSelect;
                                            if (seatSelect == 1) {
                                                if (Dan[0].getFront() == "X") {
                                                    if (Dan[0].getFrontCredit() <= credits) {
                                                        Dan[0].setFront(firstName);
                                                        vehicleType = "Sedan";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }

                                            }
                                            else if (seatSelect == 2) {
                                                if (Dan[0].getBackMid() == "X") {
                                                    if (Dan[0].getBackMidCredit() <= credits) {
                                                        Dan[0].setBackMid(firstName);
                                                        vehicleType = "Sedan";
                                                        seat = "BackMid";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 3) {
                                                if (Dan[0].getBackLeft() == "X") {
                                                    if (Dan[0].getBackLeftCredit() <= credits) {
                                                        Dan[0].setBackLeft(firstName);
                                                        vehicleType = "Sedan";
                                                        seat = "BackLeft";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 4) {
                                                if (Dan[0].getBackRight() == "X") {
                                                    if (Dan[0].getBackRightCredit() <= credits) {
                                                        Dan[0].setBackRight(firstName);
                                                        vehicleType = "Sedan";
                                                        seat = "BackRight";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 5) {
                                                getOut = true;
                                            }
                                        } while (getOut == false);
                                    }
                                    color_ = "Blue";
                                    color_t = true;
                                } while (color_t == false);
                            }









                            //BLACK
                            else if (color_num == 2) {
                                Dan[1].displaySedan();
                                do {
                                    cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                                    cout << "Enter: ";
                                    cin >> seatSelect;
                                    if (seatSelect == 1) {
                                        if (Dan[1].getFront() == "X") {
                                            if (Dan[1].getFrontCredit() <= credits) {
                                                Dan[1].setFront(firstName);
                                                vehicleType = "Sedan";
                                                seat = "Front";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }

                                    }
                                    else if (seatSelect == 2) {
                                        if (Dan[1].getBackMid() == "X") {
                                            if (Dan[1].getBackMidCredit() <= credits) {
                                                Dan[1].setBackMid(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackMid";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }
                                    }
                                    else if (seatSelect == 3) {
                                        if (Dan[1].getBackLeft() == "X") {
                                            if (Dan[1].getBackLeftCredit() <= credits) {
                                                Dan[1].setBackLeft(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackLeft";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }
                                    }
                                    else if (seatSelect == 4) {
                                        if (Dan[1].getBackRight() == "X") {
                                            if (Dan[1].getBackRightCredit() <= credits) {
                                                Dan[1].setBackRight(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackRight";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }
                                    }
                                    else if (seatSelect == 5) {
                                        getOut = true;
                                    }
                                } while (getOut == false);

                                color_ = "Black";
                                color_t = true;

                            }





                            //GREEN
                            else if (color_num == 3) {
                                Dan[2].displaySedan();
                                do {
                                    cout << "Select speficic seat [1.Front] [2.BackMid] [3.BackLeft] [4.BackRight] [5.Change Color]" << endl;
                                    cout << "Enter: ";
                                    cin >> seatSelect;
                                    if (seatSelect == 1) {
                                        if (Dan[2].getFront() == "X") {
                                            if (Dan[2].getFrontCredit() <= credits) {
                                                Dan[2].setFront(firstName);
                                                vehicleType = "Sedan";
                                                seat = "Front";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }

                                    }
                                    else if (seatSelect == 2) {
                                        if (Dan[2].getBackMid() == "X") {
                                            if (Dan[2].getBackMidCredit() <= credits) {
                                                Dan[2].setBackMid(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackMid";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }
                                    }
                                    else if (seatSelect == 3) {
                                        if (Dan[2].getBackLeft() == "X") {
                                            if (Dan[2].getBackLeftCredit() <= credits) {
                                                Dan[2].setBackLeft(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackLeft";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat,color\n";

                                        }
                                    }
                                    else if (seatSelect == 4) {
                                        if (Dan[2].getBackRight() == "X") {
                                            if (Dan[2].getBackRightCredit() <= credits) {
                                                Dan[2].setBackRight(firstName);
                                                vehicleType = "Sedan";
                                                seat = "BackRight";
                                                seat_ = true;
                                                getOut = true;
                                            }
                                            else {
                                                cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                seat_ = false;
                                            }
                                        }
                                        else {
                                            cout << "\nSeat not available. Please choose a different seat\n";

                                        }
                                    }
                                    else if (seatSelect == 5) {
                                        getOut = true;
                                    }
                                    else {
                                        cout << "invalid Color" << endl;
                                    }
                                } while (getOut == false);
                                color_ = "Green";
                                color_t = true;

                                // checks if all cars are taken
                                /*if (Dan[0].getFront() != "X" && Dan[1].getFront() == "X" && Dan[2].getFront() == "X" && Dan[0].getBackMid() == "X" && Dan[1].getBackMid() == "X" && Dan[2].getBackMid() == "X" && Dan[0].getBackLeft() == "X" && Dan[1].getBackLeft() == "X" && Dan[3].getBackLeft() == "X" && Dan[0].getBackRight() == "X" && Dan[1].getBackRight() == "X" && Dan[3].getBackRight() == "X")
                                {
                                    cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                                    color_t = true;
                                }*/
                            }
                            //while (color_t == false);





                            else if (vehicle == 3)
                            {
                                for (int i = 0; i < 3; i++)
                                {
                                    Pact[i].displayCompact();
                                }
                                do {
                                    seat = "notdone";
                                    cout << "Select a specific Color\n";
                                    cout << "Select speficic color [1.Red] [2.Blue] [3.Yellow]" << endl;
                                    cin >> color_num;

                                    //RED
                                    if (color_num == 1) {
                                        Pact[0].displayCompact();
                                        do {
                                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                                            cout << "Enter: ";
                                            cin >> seatSelect;
                                            if (seatSelect == 1) {
                                                if (Pact[0].getFront() == "X") {
                                                    if (Pact[0].getFrontCredit() <= credits) {
                                                        Pact[0].setFront(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }

                                            }

                                            else if (seatSelect == 2) {
                                                if (Pact[0].getBackLeft() == "X") {
                                                    if (Pact[0].getBackLeftCredit() <= credits) {
                                                        Pact[0].setBackLeft(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackLeft";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 3) {
                                                if (Pact[0].getBackRight() == "X") {
                                                    if (Pact[0].getBackRightCredit() <= credits) {
                                                        Pact[0].setBackRight(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackRight";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 4) {
                                                getOut = true;
                                            }
                                        } while (getOut == false);
                                        color_ = "Red";
                                        color_t = true;
                                    }




                                    //Blue
                                    else if (color_num == 2) {
                                        Pact[1].displayCompact();
                                        do {
                                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                                            cout << "Enter: ";
                                            cin >> seatSelect;
                                            if (seatSelect == 1) {
                                                if (Pact[1].getFront() == "X") {
                                                    if (Pact[1].getFrontCredit() <= credits) {
                                                        Pact[1].setFront(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }

                                            }

                                            else if (seatSelect == 2) {
                                                if (Pact[1].getBackLeft() == "X") {
                                                    if (Pact[1].getBackLeftCredit() <= credits) {
                                                        Pact[1].setBackLeft(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackLeft";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 3) {
                                                if (Pact[1].getBackRight() == "X") {
                                                    if (Pact[1].getBackRightCredit() <= credits) {
                                                        Pact[1].setBackRight(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackRight";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 4) {
                                                getOut = true;
                                            }
                                        } while (getOut == false);

                                        color_ = "Blue";
                                        color_t = true;
                                    }



                                    //Yellow
                                    else if (color_num == 3) {
                                        Pact[2].displayCompact();
                                        do {
                                            cout << "Select speficic seat [1.Front] [2.BackLeft] [3.BackRight] [4.Change Color]" << endl;
                                            cout << "Enter: ";
                                            cin >> seatSelect;
                                            if (seatSelect == '1') {
                                                if (Pact[2].getFront() == "X") {
                                                    if (Pact[2].getFrontCredit() <= credits) {
                                                        Pact[2].setFront(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "Front";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }

                                            }
                                            else if (seatSelect == 2) {
                                                if (Pact[2].getBackLeft() == "X") {
                                                    if (Pact[2].getBackLeftCredit() <= credits) {
                                                        Pact[2].setBackLeft(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackLeft";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat,color\n";

                                                }
                                            }
                                            else if (seatSelect == 3) {
                                                if (Pact[2].getBackRight() == "X") {
                                                    if (Pact[2].getBackRightCredit() <= credits) {
                                                        Pact[2].setBackRight(firstName);
                                                        vehicleType = "Compact";
                                                        seat = "BackRight";
                                                        seat_ = true;
                                                        getOut = true;
                                                    }
                                                    else {
                                                        cout << endl << firstName << " does not have enough credits. Please select a differetn option\n";
                                                        seat_ = false;
                                                    }
                                                }
                                                else {
                                                    cout << "\nSeat not available. Please choose a different seat\n";

                                                }
                                            }
                                            else if (seatSelect == 4) {
                                                getOut = true;
                                            }
                                        } while (getOut == false);

                                        color_ = "Yellow";
                                        color_t = true;
                                    }

                                    else {
                                        cout << "invalid Color" << endl;
                                    }
                                    /*if ((Pact[0].getFront() != "X") && (Pact[1].getFront() == "X") && (Pact[2].getFront() == "X") && (Pact[0].getBackLeft() == "X") && (Pact[1].getBackLeft() == "X") && (Pact[3].getBackLeft() == "X") && (Pact[0].getBackRight() == "X") && (Pact[1].getBackRight() == "X") && (Pact[3].getBackRight() == "X"))
                                    {
                                        cout << "No Space avaliable in any Truck, Please select a new Vehicle" << endl;
                                        color_t = true;
                                    }*/
                                } while (color_t == false);
                            }


                            if (seat_ == true) {
                                int num_pin = 26;
                                int max = 99;
                                int pin = 0;

                                vector<int> randNumber;
                                srand(time(NULL));
                                int nextRand;
                                int current_size;
                                set<int> pin_;

                                while (pin_.size() < num_pin)
                                {
                                    nextRand = rand() % (max + 1);
                                    current_size = pin_.size();
                                    pin_.insert(nextRand);
                                    if (current_size == pin_.size()) {
                                    }
                                    else {
                                        randNumber.push_back(nextRand);
                                    }
                                }
                                pin = nextRand;
                                reservation tempres(firstName, vehicleType, color_, pin, seat);
                                reserved.push_back(tempres);
                                cout << "you have successfully made a new reservation. Your new Pin is :" << pin << endl;
                                resChanged = true;
                            }
                            else if (seat_ == false) {
                                cout << "\nUnable to make reservation. Please Try Again.\n";
                            }
                            else {
                                cout << "\nUnknown Issue. Please Try Again\n";
                            }



                        }//comparison if for name and pin
                        else {
                            cout << "\nName and/or Pin do not match or may not exits. Try Again.\n";
                        }// else for not found 
                    } // for loop searching reserved vector
                } while (foundCheck = true);//do while loops while searching for matching pin and name
            } while (resChanged == true);//do while loops if res no chnaged 


        }

        case 3: {
            string nameS;
            int pin = 0;
            cout << "Delete reservation" << endl;
            cout << "------------------------" << endl;
            cout << "\nWhat is the name used on the Reservation?: ";
            cin >> nameS;
            cout << "\nWhat is the PIN for the Reservation?: ";
            cin >> pin;
            for (int k = 0; k < reserved.size(); ++k) {
                if (reserved.at(k).getName() == nameS && reserved.at(k).getPin() == pin) {
                    //foundCheck = true;
                    cout << "\nServation Found. Deleting reservation...\n";
                    reserved.erase(reserved.begin() + k);

                    cout << "\nReservation removed.\n";
                    cout << "------------------------" << endl;
                }
            }
            break; }
        case 4: {
            //ends program
            cout << "Display Vehicles";
            for (int i = 0; i < 3; i++)
            {
                Truck[i].displayPickup();
            }
            for (int i = 0; i < 3; i++)
            {
                Pact[i].displayCompact();
            }
            for (int i = 0; i < 3; i++)
            {
                Dan[i].displaySedan();
            }

            break; }
        case 5: {
            //ends program
            cout << "Print Vehicle Assignments" << endl;
            cout << "------------------------" << endl;

            break; }
        case 6: {
            //ends program
            cout << "Option 4: Quitting Program.......";
            break; }
        default:
            //defualt 
            cout << "Invalid choice. Please enter a number from 1 - 6";

        }



    } while (opt != '6');
}//main