#pragma once
#include <string>
#include <vector>

using namespace std;


class team_mem
{
prodected:
	string first_name;
	string last_name;
	int credit;

public:
	team_mem();
	team_mem(string, string, int);
	void DisplayMemInfo();
};