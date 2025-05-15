#include <iostream>

using namespace std;

// Base class with a pure virtual function
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Derived class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;

    }
};

int main() {
    // // Shape    s; // Cannot create an object of an abstract class

    // Circle c;
    // c.draw(); // Output: Drawing a circle

    // Rectangle r;
    // r.draw(); // Output: Drawing a rectangle
    Shape *s;
    Circle c;
   s = &c;
   s->draw();
    Rectangle r;
   s  = &r;
    return 0;
}