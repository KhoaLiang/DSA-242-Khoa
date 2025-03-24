#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define EPSILON (1E-8)

class Point
{
private:
    float x, y, z;
    friend ostream &operator<<(ostream &os, const Point &point);

public:
    Point(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    Point(const Point &point);

    void setX(float x);
    float getX() const;
    void setY(float y);
    float getY() const;
    void setZ(float z);
    float getZ() const;

    float radius() const;

    operator float();

    bool operator==(Point rhs) const;

    // Compare by x, y, z and radius
    static bool pointEQ_X(Point &lhs, Point &rhs);
    static bool pointEQ_Y(Point &lhs, Point &rhs);
    static bool pointEQ_Z(Point &lhs, Point &rhs);
    static bool pointEQ_Radius(Point &lhs, Point &rhs);
    static bool pointEQ(Point &lhs, Point &rhs);

    // Comparison functions for pointers
    static bool pointEQ_X(Point *&lhs, Point *&rhs);
    static bool pointEQ_Y(Point *&lhs, Point *&rhs);
    static bool pointEQ_Z(Point *&lhs, Point *&rhs);
    static bool pointEQ_Radius(Point *&lhs, Point *&rhs);
    static bool pointEQ(Point *&lhs, Point *&rhs);

    // Conversion to string
    static string point2str_X(Point &point);
    static string point2str_Y(Point &point);
    static string point2str_Z(Point &point);
    static string point2str_Radius(Point &point);
    static string point2str(Point &point);

    // Conversion to string for pointers
    static string point2str_X(Point *&point);
    static string point2str_Y(Point *&point);
    static string point2str_Z(Point *&point);
    static string point2str_Radius(Point *&point);
    static string point2str(Point *&point);

    // Point operations
    static void pointRemove(Point *point);
    static Point *genPoints(int size, float minValue = 0, float maxValue = 1,
                            bool manualSeed = false, int seedValue = 0);
    static void println(Point *head, int size);
};

#endif /* POINT_H */
