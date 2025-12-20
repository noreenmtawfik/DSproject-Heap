#include <iostream>
#include "Scheduler.h"

using namespace std;

// ==========================================
// 1. Customer Implementation
// ==========================================
Customer::Customer() {
    id = 0; arrivalTime = 0; cookTime = 0;
}

Customer::Customer(int id, float arrival, float cook) {
    this->id = id;
    this->arrivalTime = arrival;
    this->cookTime = cook;
}

bool Customer::operator<(const Customer& other) const {
    return this->cookTime < other.cookTime;
}

// ==========================================
// 2. Scheduler Implementation
// ==========================================

// Constructor
Scheduler::Scheduler(int n) {
    count = n;
    allCustomers = new Customer[count];
}

// Destructor
Scheduler::~Scheduler() {
    if (allCustomers != NULL) delete[] allCustomers;
}

// Add Customer
void Scheduler::addCustomer(int index, const Customer& c) {
    if (index < count) allCustomers[index] = c;
}

// --- Merge Sort Logic (Hidden inside cpp) ---
void Scheduler::merge(Customer* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Customer* L = new Customer[n1];
    Customer* R = new Customer[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Sort by Arrival Time
        if (L[i].arrivalTime <= R[j].arrivalTime) {
            arr[k] = L[i]; i++;
        } else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

void Scheduler::mergeSort(Customer* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// --- Solve Function (The Brain) ---
void Scheduler::solve() {
    // 1. Sort by Arrival
    mergeSort(allCustomers, 0, count - 1);
    
    cout << "\n--- Simulation Started (SJF Logic) ---\n" << endl;

    float currentTime = 0;
    int index = 0;

    while (index < count || !heap.isEmpty()) {
        
        // Gap Handling
        if (heap.isEmpty() && index < count && currentTime < allCustomers[index].arrivalTime) {
            cout << "[Time " << currentTime << "] Oven idle... Skipping to " 
                 << allCustomers[index].arrivalTime << endl;
            currentTime = allCustomers[index].arrivalTime;
        }

        // Arrival Handling
        while (index < count && allCustomers[index].arrivalTime <= currentTime) {
            heap.push(allCustomers[index]);
            cout << "[Time " << currentTime << "] Customer " << allCustomers[index].id 
                 << " arrived (Cook: " << allCustomers[index].cookTime << ")" << endl;
            index++;
        }

        // Cooking Handling
        if (!heap.isEmpty()) {
            Customer current = heap.pop();
            float waitTime = currentTime - current.arrivalTime;
            currentTime += current.cookTime;

            cout << "[Time " << currentTime << "] Finished Customer " << current.id 
                 << " (Waited: " << waitTime << " mins)\n";
        }
    }
    cout << "\n--- Simulation Ended Successfully ---" << endl;
}