#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero x-y coordinate
         */
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x = x;
        this->y = y;
    }

    void setX(double x)
    {
        /*  
         * STUDENT ANSWER
         */
        this->x = x;
    }

    void setY(double y)
    {
        /*  
         * STUDENT ANSWER
         */
        this->y = y;
    }

    double getX() const
    {
        /*  
         * STUDENT ANSWER
         */
        return x;
    }

    double getY() const
    {
        /*  
         * STUDENT ANSWER
         */
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        double dx = this->x - pointA.getX();
        double dy = this->y - pointA.getY();
        double distanceSquared = dx * dx + dy * dy;
        return sqrtBabylonian(distanceSquared);
    }

    double sqrtBabylonian(double n)
    {
        double x = n;
        double y = 1;
        double e = 0.000001; // e decides the accuracy level
        while (x - y > e)
        {
            x = (x + y) / 2;
            y = n / x;
        }
        return x;
    }
};

int main() {
    Point A(2, 3);
    cout << A.getX() << " " << A.getY() << endl;

    Point B(1, 1);
    cout << pow(A.distanceToPoint(B), 2) << endl;

    return 0;
}