#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm> 
#include <cassert> 
#include <new> 

using namespace std;

template <typename T>
class Heap {
private:
    T* array;
    int capacity;
    int count;

    void resize();
    
    void percolateUp(int child);   
    void percolateDown(int parent); 

public:
    Heap();
    Heap(int capacity); 
    ~Heap();
    
    void push(T element);
    T pop();
    T top();
    bool isEmpty();
    int size();
};


#endif