#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Heap.h" // لازم يكون جنبه ملف Heap.h

// تعريف الزبون (لازم يكون هنا عشان main يشوفه)
struct Customer {
    int id;
    float arrivalTime;
    float cookTime;

    Customer();
    Customer(int id, float arrival, float cook);
    bool operator<(const Customer& other) const;
};

// تعريف الكلاس
class Scheduler {
private:
    Customer* allCustomers;
    int count;
    Heap<Customer> heap;

    // دوال الترتيب (Private Helpers)
    void merge(Customer* arr, int l, int m, int r);
    void mergeSort(Customer* arr, int l, int r);

public:
    Scheduler(int n);
    ~Scheduler();
    void addCustomer(int index, const Customer& c);
    void solve();
};

#endif