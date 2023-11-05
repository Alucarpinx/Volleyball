#include "team.h"
#include <iostream>

using namespace std;

team_mem::team_mem() {

}

team_mem::team_mem(string first, string last, int cred) {
    first_name = first;
    last_name = last;
    credits = cred;
}

void team_mem::DisplayMemInfo() {
    cout << first_name << " " << last_name << "has " << credits << "credits\n";
}