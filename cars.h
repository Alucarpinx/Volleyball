#pragma once
#include <string>
#include <iomanip>

using namespace std;

class compact {
private:
	int capacity = 3;
public:
	string color;
	int driver;
	int frontSeat;
	int backLeftSeat;
	int backRightSeat;
	int backMiddleSeat;
	void displayCompact();
};
class truck {
private:
	int capacity = 1;
public:
	string color;
	void displayTruck();
};
class sedan  {
private:
	int capacity = 4;
public:
	string color;
	void displaySedan();
};