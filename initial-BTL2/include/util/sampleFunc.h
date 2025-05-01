#ifndef SAMPLEFUNC_H
#define SAMPLEFUNC_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

#include "util/Point.h"
#include "util/ArrayLib.h"

// Mark functions as inline
inline int minHeapComparator(int& a, int& b) {
    return (a < b) ? -1 : (a > b) ? 1 : 0;
}

inline int maxHeapComparator(int& a, int& b) {
    return (a > b) ? -1 : (a < b) ? 1 : 0;
}

inline int minHeapComparator(Point& a, Point& b) {
    float ra = sqrt(a.getX() * a.getX() + a.getY() * a.getY());
    float rb = sqrt(b.getX() * b.getX() + b.getY() * b.getY());
    return (ra < rb) ? -1 : (ra > rb) ? 1 : 0;
}

inline int maxHeapComparator(Point& a, Point& b) {
    float ra = sqrt(a.getX() * a.getX() + a.getY() * a.getY());
    float rb = sqrt(b.getX() * b.getX() + b.getY() * b.getY());
    return (ra > rb) ? -1 : (ra < rb) ? 1 : 0;
}

inline int minHeapComparator(Point*& a, Point*& b) {
    float ra = sqrt(a->getX() * a->getX() + a->getY() * a->getY());
    float rb = sqrt(b->getX() * b->getX() + b->getY() * b->getY());
    return (ra < rb) ? -1 : (ra > rb) ? 1 : 0;
}

inline int maxHeapComparator(Point*& a, Point*& b) {
    float ra = sqrt(a->getX() * a->getX() + a->getY() * a->getY());
    float rb = sqrt(b->getX() * b->getX() + b->getY() * b->getY());
    return (ra > rb) ? -1 : (ra < rb) ? 1 : 0;
}

inline string point2str(Point& point) {
    stringstream os;
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os.str();
}

inline string point2str(Point*& point) {
    stringstream os;
    os << "(" << point->getX() << ", " << point->getY() << ")";
    return os.str();
}

inline string int2str(int& value) {
    stringstream os;
    os << value;
    return os.str();
}

inline string int2str(int*& value) {
    stringstream os;
    os << *value;
    return os.str();
}



#endif /* SAMPLEFUNC_H */