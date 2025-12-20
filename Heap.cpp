// ملحوظة: متعمليش include لـ Heap.h هنا
// الكود ده هيتنسخ أوتوماتيك جوه الـ .h
#include "Heap.h"
// 1. Constructor
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

// 2. Destructor
template <typename T>
Heap<T>::~Heap() {
    if (array != NULL) {
        delete[] array;
    }
}

// 3. Resize
template <typename T>
void Heap<T>::resize() {
    capacity *= 2;
    T* myarray = new (nothrow) T[capacity];
    
    // التأكد إن الميموري تمام
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

// 4. Percolate Up
template <typename T>
void Heap<T>::percolateUp(int child) {

    while (child > 0) {
        int parent = (child - 1) / 2;
        
        // المقارنة بتعتمد على operator في الـ struct بتاعكم
        if (array[child] < array[parent]) {
            swap(array[child], array[parent]);
            child = parent; // كمل طلوع
        } 
        else {
            break; // وصل لمكانه الصح
        }
    }
}

// 5. Percolate Down
template <typename T>
void Heap<T>::percolateDown(int parent) {
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;
    int smallest = parent;

    // هل الابن الشمال موجود؟ وهل هو "أصغر" مني؟
    if (leftChild < count && array[leftChild] < array[smallest]) {
        smallest = leftChild;
    }

    // هل الابن اليمين موجود؟ وهل هو "أصغر" من الفايز لحد دلوقتي؟
    if (rightChild < count && array[rightChild] < array[smallest]) {
        smallest = rightChild;
    }

    // لو الأب مش هو "الأصغر"، بدله مع ابنه وكمل نزول
    if (smallest != parent) {
        swap(array[parent], array[smallest]);
        percolateDown(smallest); // Recursion
    }
}

// 6. Push
template <typename T>
void Heap<T>::push(const T& element) {
    if (count == capacity) {
        resize();
    }
    array[count] = element; // حطه في الآخر
    percolateUp(count);     // طلعه لمكانه الصح
    count++;
}

// 7. Pop
template <typename T>
T Heap<T>::pop() {
    if (isEmpty()) return T(); // أمان لو فاضية
        
    T root = array[0]; // خد نسخة من المدير
    
    // هات آخر موظف حطه مكان المدير
    array[0] = array[count - 1];
    count--;
    
    if (count > 0) {
        percolateDown(0); // صلحه (نزله لمكانه الصح)
    }
    
    return root;
}

// 8. Top
template <typename T>
T Heap<T>::top() {
    if (isEmpty()) return T();
    return array[0];
}

// 9. Helpers
template <typename T>
bool Heap<T>::isEmpty() {
    return (count == 0);
}

template <typename T>
int Heap<T>::size() {
    return count;
}