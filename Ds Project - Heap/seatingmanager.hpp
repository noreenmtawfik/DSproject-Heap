#ifndef seatingmanager
#define seatingmanager
#define Emptychairs
#define bestseatcomparator

#include <iostream>
#include <vector>
using namsepace std;

class seatingmanager {
private:
    int numchairs;
    Priorityqueue<Emptychairs, bestseatcomparator> pq;
    vector<int> Customer;
    bool preference;

public:
    seatingmanager(int numchairs, bool preference);
    seatcustomers(vector<int> Customer);
    customerat(vector<int> Customer);
}