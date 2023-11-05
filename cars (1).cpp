#include "cars.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstdlib>	
#include <string>

using namespace std;

//cars::cars()
//{
//
//}
//cars::cars(string colors_, int seats_)
//{
//	color = colors_;
//	seats = seats_;
//}
//void cars::DisplayAllCars()
//{
//	
//}
//
//compact::compact()
//{
//
//}
//compact::compact(string color_, int num_)
//{
//	color = color_;
//	capacity = num_;
//}
//void compact::displayCompact()
//{
//	if (color == "PURPLE") {
//
//	}
//}
//
//truck::truck()
//{
//
//}
//truck::truck(string color_, int num_)
//{
//	color = color_;
//	capacity = num_;
//}
//void truck::displayTruck()
//{
//
//}

sedan::sedan()
{

}
sedan::sedan(string color_, int num_)
{
	color = color_;
	capacity = num_;
}
void sedan::displaySedan()
{

    //LOOKS WEIRD BUT TRUST IT WORKS
    cout << "    _________________________________" << endl;
    cout << "  /                                   \\" << endl;
    cout << " /                   "<< color << "                    \\" << endl;
    cout << "/                                         \\" << endl;
    cout << "| " << "     _____________________________      |" << endl;
    cout << "| " << "    /                             \\     |" << endl;
    cout << "| " << "   /                               \\    |" << endl;
    cout << "| " << "  /                                 \\   |" << endl;
    cout << "| " << "  |__________________________________|  |" << endl;
    cout << "| " << endl << "| " << endl;
    cout << "|" << " [ " << "front seat name here" << " ]" << "  " << "[ " << "front seat name here" << " ]   |" << endl;
    cout << "|" << endl;
    cout << "|" << endl;
    cout << "|" << " [ " << "back left" << " ]" << " [ " << "back middle" << " ]" << " [ " << "back right" << " ]    |" << endl;
    cout << "|                                         |" << endl;
    cout << "|                                         |" << endl;
    cout << "|                                         |" << endl;
    cout << "|                                         |" << endl;
    cout << "|                                         |" << endl;
    cout << "|                                         |" << endl;
    cout << " \\                                       /" << endl;
    cout << "  \\___________________________________ /" << endl;
}