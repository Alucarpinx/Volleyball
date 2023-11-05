//#include "dodgeball.h"
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
    string NunDriverlast;
    int credits;

    vector<team_mem> Driver;
    string Driver_first;
    string Driver_last;

    team_mem tempmem;

    string word;
    vector words;
    bool second = 0;

    while (inFile.good()) {
        inFile >> word;
        words.push_back(word);
    }
    for (string word : words) {
        for (int i = 0; i < 9; i++) {
            if (second == 1) {
                string last = word;
                !second;
            }
            else {
                string first = word;
                !second;
            }
            team_mem tempName(first, last);
            Drive.push_back(team_mem);
        }
        for (int i = 9; i <= inFile.eof(); i++) {
       
    }


  /*  while (inFile.good()) {







*/

    //    / for (int i = 0; i < 9; i++) {
    //        getline(inFile, Driver_first);
    //        getline(inFile, Driver_last);
    //        team_mem tempName(Driver_first, Driver_last);
    //        Drive.push_back(team_mem);
    //    }
    //    for (int i = 9; i <= inFile.eof(); i++) {
    //        getline(inFile, Driver_first);
    //        getline(inFile, Driverlast);
    //        getline(inFile, credits);
    //        team_mem tempName(Driver_first, Driverlast, credits);
    //        nun_Drive.push_back(team_mem);
    //    } /

 }