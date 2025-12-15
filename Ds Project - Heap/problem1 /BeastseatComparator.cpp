#include <iostream>
#include "BestseatComparator.hpp"
using namespace std;
//rage3 di
class BestseatComparator{


    bool operator<()(const Emptychairs& seg1, const Emptychairs& seg2) const {
        return seg1.length() > seg2.length();
        //el mfrood tb2a this.length() , w lazem n4eel el class da w n-overload f emptychairs, w el overloas=ding bya5od a single parameter
    }
}
