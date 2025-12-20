#include <iostream>
#include "seatingmanager.hpp"

using namespace std;

int main() {

    // Number of chairs
    int numChairs = 10;

    // preference = true  -> left middle
    // preference = false -> right middle
    bool preference = true;

    seatingmanager manager(numChairs, preference);

    cout << "Seating customers...\n";

    // Seat customers with IDs 1, 2, 3, ...
    for (int id = 1; id <= numChairs; id++) {
        manager.seatcustomer(id);

        cout << "After seating customer " << id << ": ";
        manager.printSeating();
    }

    cout << "\nFinal seating state:\n";
    manager.printSeating();

    cout << "\nTesting customerAt():\n";
    for (int i = 0; i < numChairs; i++) {
        cout << "Chair " << i << ": Customer "
             << manager.customerat(i) << endl;
    }

    return 0;
}

