#include <iostream>
using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};

Character::Character() {
    // STUDENT ANSWER
    this->hp = 0;
    this->x = 0;
    this->y = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;
}

int Character::getHp() {
    // STUDENT ANSWER
    return hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // Calculate the Manhattan distance
    return abs(this->x - other->getX()) + abs(this->y - other->getY());
}

int main() {
    // Test default constructor
    Character char1;
    cout << "Character 1 - HP: " << char1.getHp() << ", X: " << char1.getX() << ", Y: " << char1.getY() << endl;

    // Test parameterized constructor
    Character char2(100, 5, 10);
    cout << "Character 2 - HP: " << char2.getHp() << ", X: " << char2.getX() << ", Y: " << char2.getY() << endl;

    // Test set and get methods
    char1.setHp(50);
    char1.setX(3);
    char1.setY(7);
    cout << "Character 1 (after setting values) - HP: " << char1.getHp() << ", X: " << char1.getX() << ", Y: " << char1.getY() << endl;

    // Test Manhattan distance
    int distance = char1.getManhattanDistTo(&char2);
    cout << "Manhattan distance between Character 1 and Character 2: " << distance << endl;

    return 0;
}