#pragma once
#include <string>
#include <iostream>

using namespace std;

class reservation {
//private:
//	string first_name;
//	string vehicle;
//	string vehicleColor;
//	string seat;
//	int PIN;
public:
	string first_name;
	string vehicle;
	string vehicleColor;
	string seat;
	int PIN;
private:
	void reserveReservation(string);
	void modifyReservation();
	void deleteReservation();
	void printVehicle();
	void printReservations();
	void displayVehicles();
};

