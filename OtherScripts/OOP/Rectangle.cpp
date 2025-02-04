// Source: https://www.w3resource.com/cpp-exercises/oop/cpp-oop-exercise-2.php
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w){
        this->length = l;
        this->width = w;
    }
    double getArea(){
        return length*width;
    }
    double getPerimeter(){
        return 2 * (length + width);
    }
};

int main() {
    double length, width;
    cout << "Input the length of the rectangle: ";
    cin >> length;
    cout << "Input the width of the rectangle: ";
    cin >> width;

    Rectangle rectangle(length, width);
    cout << "Area: " << rectangle.getArea() << endl;
    cout << "Perimeter: " << rectangle.getPerimeter() << endl;

    return 0;
}