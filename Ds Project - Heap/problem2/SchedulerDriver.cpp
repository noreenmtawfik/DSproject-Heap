#include <iostream>
#include "Scheduler.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of customers: ";
    if (!(cin >> n)) return 0;

    Scheduler pizzaSystem(n);

    cout << "Enter details (ID Arrival Cook):\n";
    for (int i = 0; i < n; i++) {
        int id;
        float arrival, cook;
        cin >> id >> arrival >> cook;
        pizzaSystem.addCustomer(i, Customer(id, arrival, cook));
    }

    pizzaSystem.solve();

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    
    return 0;
}