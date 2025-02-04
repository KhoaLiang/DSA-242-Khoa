//Write a C++ program to implement a class called Circle that has private member variables for radius. Include member functions to calculate the circle's area and circumference.
//Source: https://www.w3resource.com/cpp-exercises/oop/cpp-oop-exercise-1.php
#include <iostream>

using namespace std;


const double PI = 3.14159; // Define the value of PI as a constant
class Circle {
private:
    double radius;

public:
    //constructor
    Circle(){
        this->radius = 0;
    }
    Circle(double r){
        this->radius = r;
    }
    double getArea(){
        return PI * radius * radius;
    }
    double getCircumference(){
        return 2 * PI * radius;
    }
};


int main() {
    double radius;
    cout << "Input the radius of the circle: ";
    cin >> radius;

    Circle circle(radius);
    cout << "Area: " << circle.getArea() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;

    return 0;
}