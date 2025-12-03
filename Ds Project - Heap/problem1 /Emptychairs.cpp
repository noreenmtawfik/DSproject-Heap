#include "EmptyChair.hpp"
using namespace std;

EmptyChair::EmptyChair(int l, int r) : left(l), right(r) {
    if (left > right) {
        cerr << "Invalid segment: left > right";
    }
}

 bool EmptyChair::isempty() const {
    return length() == 0;
}


int EmptyChair::length() const { 
    return right - left + 1;
}

int EmptyChair::distance() const { 
    return (length() - 1) / 2;
}

int EmptyChair::middleseat(bool preference) const{
    int middle_index = (left + right)/2;
    int len = length();
    //if odd length
    if (len % 2 == 1) { 
        return middle_index + 1;  
    }
    else { 
        return preference ? middle_index / 2  : (middle_index / 2) +1 ; 
    }

}
                    