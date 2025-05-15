#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    double R;

    cout << "Enter values for x, y, and z: ";
    cin >> x >> y >> z;

    try {
        if (x - y == 0) {
            throw "Division by zero error!";
        } else {
            R = static_cast<double>(z) / (x - y);
            cout << "R = " << R << endl;
        }
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }

    return 0;
}