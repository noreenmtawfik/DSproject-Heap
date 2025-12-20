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
    
    // رجعتلك الأسماء هنا child و parent زي ما طلبتي
    void percolateUp(int child);   
    void percolateDown(int parent); 

public:
    Heap();
    Heap(int capacity); // ضفتلك ده زيادة عشان لو حبيتي تحددي الحجم من البداية
    ~Heap();
    
    void push(const T& element);
    T pop();
    T top();
    bool isEmpty();
    int size();
};



#endif