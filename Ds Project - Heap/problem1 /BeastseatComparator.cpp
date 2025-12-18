#include <iostream>
#include "BestseatComparator.hpp"
using namespace std;
//rage3 di
class BestseatComparator{


bool operator()(const EmptyChair& seg1,const EmptyChair& seg2) const {
    if (seg1.distance() != seg2.distance())
        return seg1.distance() > seg2.distance(); // الأكبر أفضل
    return seg1.left < seg2.left;                 // tie-break
}
}
/*//bool operator<()(const Emptychairs& seg1, const Emptychairs& seg2) const {
        //return seg1.length() > seg2.length();
        //el mfrood tb2a this.length() , w lazem n4eel el class da w n-overload f emptychairs, w el overloas=ding bya5od a single parameter
        
    //}*/