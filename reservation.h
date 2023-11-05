#pragma once
#include <string>
#include <vector>

using namespace std;


class reservation : public truck, public sadan, public compact
{
private:
	string first_name;
	string last_name;
	int credit;

public:
	reservation();
	void reserveReservation(string firstName);
    void modifyReservation();
    void deleteReservation();
    void displayVehicles();
    void printVehicle();
    void printReservations();
    void reserveSeat(string firstName)
};