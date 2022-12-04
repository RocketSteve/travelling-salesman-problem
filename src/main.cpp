#include "classes/Coordinate/Coordinate.h"
#include "classes/Coordinate/Coordinate.cpp"
#include <iostream>
int main(){
    auto *pPoint = new Coordinate(10.0, 10);
    std::cout<<pPoint->to_string()<<std::endl;
    return 0;
}