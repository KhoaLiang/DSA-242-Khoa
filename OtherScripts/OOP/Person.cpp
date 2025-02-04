// source: https://www.w3resource.com/cpp-exercises/oop/cpp-oop-exercise-3.php
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string country;

public:
    void setName(string n){
        this->name = n;
    }
    string getName(){
        return name;
    }
    void setAge(int a){
        this->age = a;
    }
    int getAge(){
        return age;
    }
    void setCountry(string c){
        this->country = c;
    }
    string getCountry(){
        return country;
    }
};

int main() {
    Person person;
    string name = "Khoa";
    int age = 23;
    string country = "Sweden";

    // cout << "Name: ";
    // getline(cin, name);
    person.setName(name);

    // cout << "Age: ";
    // cin >> age;
    person.setAge(age);

    // cout << "Country: ";
    // getline(cin, country);
    person.setCountry(country);

    cout << "Name: " << person.getName() << endl;
    cout << "Age: " << person.getAge() << endl;
    cout << "Country: " << person.getCountry() << endl;

    return 0;
}