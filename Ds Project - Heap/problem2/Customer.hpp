#ifndef Customer
#define Customer

#include <iostream>
using namsepace std;

    struct Customer{

    int orderId, arrivalTime;
    float cookTime;

   Customer();
   Customer(int orderID,int arrivalTime,float cookTime);
}
