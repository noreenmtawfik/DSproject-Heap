#include <iostream>
#include "BestseatComparator.hpp"
using namespace std;

class BestseatComparator{
    bool operator>()(const Emptychairs& seg1, const Emptychairs& seg2) const {
        return seg1.length() < seg2.length();
    }
}
