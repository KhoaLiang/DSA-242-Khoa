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

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle()
    {
        /*  
         * STUDENT ANSWER   
         * TODO: set zero center's x-y and radius
         */
        center.setX(0);
        center.setY(0);
        this->radius = 0;
    }

    Circle(Point center, double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->center.setX(center.getX());
        this->center.setY(center.getY());
        this->radius = radius;
    }

    Circle(const Circle &circle)
    {
        this->center.setX(circle.center.getX());
        this->center.setY(circle.center.getY());
        this->radius = circle.radius;
    }
    
    void setCenter(Point point)
    {
        /*  
         * STUDENT ANSWER
         */
        this->center.setX(point.getX());
        this->center.setY(point.getY());
    }

    void setRadius(double radius)
    {
        /*  
         * STUDENT ANSWER
         */
        this->radius = radius;
    }

    Point getCenter() const
    {
        /*  
         * STUDENT ANSWER
         */
        return center;
    }

    double getRadius() const
    {
        /*  
         * STUDENT ANSWER
         */
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};
int main() {
    // Test Point class
    Point A(2, 3);
    cout << A.getX() << " " << A.getY() << endl;

    Point B(1, 1);
    cout << pow(A.distanceToPoint(B), 2) << endl;

    // Test Circle class
    Point center(5, 5);
    Circle C(center, 10);
    C.printCircle();

    Circle D;
    D.setCenter(Point(3, 4));
    D.setRadius(7);
    D.printCircle();

    Circle E(C);
    E.printCircle();

    return 0;
}