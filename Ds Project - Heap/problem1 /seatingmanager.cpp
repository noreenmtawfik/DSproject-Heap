#include "seatingmanager.hpp"
using namespace std;

seatingmanager::seatingmanager() : numchairs(0), preference(true), Customer(nullptr) {}

seatingmanager::seatingmanager(int numchairs, bool preference) : numchairs(numchairs), preference(preference) {
    
    Customer = new int[numchairs]; 
    for (int i = 0; i < numchairs; i++)
        Customer[i] = 0;

    EmptyChair intialSeg(0,numchairs-1);
    hp.push(intialSeg);
}

seatingmanager::~seatingmanager() {
    if(Customer != nullptr)
        delete[] Customer;
}

void seatingmanager::seatcustomer(int customerID) {
    if (hp.isEmpty()) {
        cout << "No empty segments left! Cannot seat customer " << customerID << endl;
        return;
    }

    EmptyChair bestSegment = hp.pop();
    int seat = bestSegment.middleseat(preference);
    Customer[seat] = customerID;
    //b3ml left segment
    EmptyChair leftSegment(bestSegment.left, seat - 1);
    if (bestSegment.left <= seat - 1) {
        hp.push(leftSegment);
    }
   
    // w hna el right sgement
    EmptyChair rightSegment(seat + 1, bestSegment.right);
    if (seat + 1 <= bestSegment.right) {
        hp.push(rightSegment);
    }
    
    
}

int seatingmanager::customerat(int pos)const{
    if (pos < 0 || pos >= numchairs) {
        cerr << "Invalid chair position!" << endl;
        return -1;
    }
    return Customer[pos];
}

int seatingmanager::printSeating()const{
    for (int i = 0; i < numchairs; i++) {
        if (Customer[i] != 0) {  // skip empty seats
            cout << seat << " ";
        }
    }
    cout << endl;
}