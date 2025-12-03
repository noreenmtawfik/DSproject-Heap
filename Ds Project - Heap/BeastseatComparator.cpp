#include <iostream>
using namespace std;
#ifdef bestseatcomparator


class BestseatComparator{
    bool operator>()(const Emptychairs& seg1, const Emptychairs& seg2) const {
        return seg1.length() < seg2.length();
    }
}

#endif