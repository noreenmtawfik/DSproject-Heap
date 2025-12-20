#include "Heap.hpp" 

template <typename T>
Heap<T>::Heap() {
    capacity = 20;
    count = 0;
    array = new (nothrow) T[capacity];
    assert(array != NULL);
}

template <typename T>
Heap<T>::Heap(int cap) {
    this->capacity = cap;
    count = 0;
    array = new (nothrow) T[capacity];
    assert(array != NULL);
}


template <typename T>
Heap<T>::~Heap() {
    if (array != NULL) {
        delete[] array;
    }
}


template <typename T>
void Heap<T>::resize() {
    capacity *= 2;
    T* myarray = new (nothrow) T[capacity];
    
    
    if (!myarray) { 
        cerr << "Memory allocation failed!" << endl;
        exit(1); 
    }

    for (int i = 0; i < count; i++) {
        myarray[i] = array[i];
    }
    delete[] array;
    array = myarray;
}


template <typename T>
void Heap<T>::percolateUp(int child) {

    while (child > 0) {
        int parent = (child - 1) / 2;
        
        
        if (array[child] < array[parent]) {
            swap(array[child], array[parent]);
            child = parent; 
        } 
        else {
            break; 
        }
    }
}


template <typename T>
void Heap<T>::percolateDown(int parent) {
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int smallest = parent;

    
    if (leftChild < count && array[leftChild] < array[smallest]) {
        smallest = leftChild;
    }

    
    if (rightChild < count && array[rightChild] < array[smallest]) {
        smallest = rightChild;
    }

    
    if (smallest != parent) {
        swap(array[parent], array[smallest]);
        percolateDown(smallest); 
    }
}


template <typename T>
void Heap<T>::push(const T& element) {
    if (count == capacity) {
        resize();
    }
    array[count] = element; 
    percolateUp(count);    
    count++;
}


template <typename T>
T Heap<T>::pop() {
    if (isEmpty()) return T(); 
        
    T root = array[0]; 
    
    
    array[0] = array[count - 1];
    count--;
    
    if (count > 0) {
        percolateDown(0); 
    }
    
    return root;
}


template <typename T>
T Heap<T>::top() {
    if (isEmpty()) return T();
    return array[0];
}


template <typename T>
bool Heap<T>::isEmpty() {
    return (count == 0);
}

template <typename T>
int Heap<T>::size() {
    return count;
}