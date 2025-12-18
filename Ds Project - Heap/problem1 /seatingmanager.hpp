#ifndef SEATINGMANAGER_HPP
#define SEATINGMANAGER_HPP

#include "BeastseatComparator.hpp"
#include "Emptychairs.hpp"
#include "Heap.hpp"

#include <iostream>

using namespace std;

class seatingmanager {
private:
    int numchairs;
    Heap <Emptychairs, bestseatcomparator> hp;
    int* Customer;
    bool preference;

public:
    seatingmanager();
    seatingmanager(int numchairs, bool preference);
    void seatcustomer(int customerID);
    int customerat(int pos)const;
    void printSeating() const;
    ~seatingmanager();
};
#endif 
