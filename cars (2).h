#pragma once
#include <string>
#include <iomanip>

using namespace std;

//class cars {
//private:
//    int seats;
//    string color;
//public:
//    cars();
//    cars(string, int);
//    void DisplayAllCars();
//};

//class compact : public virtual cars {
//private:
//    int capacity = 3;
//    string color;
//    string driver_first;
//    string driver_last;
//public:
//    compact();
//    compact(string, int);
//    void displayCompact();
//};
//
//class truck : public virtual cars {
//private:
//    int capacity = 1;
//    string color;
//    string driver_first;
//    string driver_last;
//public:
//    truck();
//    truck(string, int);
//    void displayTruck();
//};

class sedan : public virtual cars{
private:
    int capacity = 4;

    string color;
    string driver_first;
    string driver_last;

    string Front_name;
    string BackMid_name;
    string BackLeft_name;
    string BackRight_name;

    bool front = true;
    bool back_mid = true;
    bool back_left = true;
    bool back_right = true;

public:
    sedan();
    sedan(string, int);
    //void Check_seats();
    bool resevered_seats(int);
    void displaySedan();
};