#include "seatingmanager.hpp"
using namespace std;

seatingmanager::seatingmanager() : numchairs(0), preference(true), Customer(nullptr) {}

seatingmanager::seatingmanager(int numchairs, bool preference) : numchairs(numchairs), preference(preference) {
    
    Customer = new int[numchairs]; // تخصيص مساحة للكرسي الواحد لكل index
    for (int i = 0; i <= numchairs; i++)
        Customer[i] = 0;

    EmptyChair intialSeg(0,numchairs-1);
}

seatingmanager::seatcustomer(int customerID): numchairs(0), preference(true) {}