#include "EmptyChair.hpp"
using namespace std;
EmptyChair::EmptyChair(int l, int r) : left(l), right(r) {}
int EmptyChair::length() const { return right - left + 1; }
int EmptyChair::distance() const { return (length() - 1) / 2; }
int EmptyChair::middleseat(bool preference;) const{
                                                    int len = length();
                                                    if (len % 2 == 1) { 
                                                    return left + len / 2;  
                                                 }
                                                 else { 
                                                    return preference ? left + len / 2 - 1 : left + len / 2; 
                                                }
                                                
                                            }
                    