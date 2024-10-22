/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;

class complex {
    float x;  // Real part
    float y;  // Imaginary part
public:
    // Default constructor
    complex() {
        x = 0;
        y = 0;
    }

    // Overloaded addition operator
    complex operator+(complex);

    // Overloaded multiplication operator
    complex operator*(complex);

    // Friend function for input (overloading >> operator)
    friend istream& operator>>(istream &input, complex &t) {
        cout << "Enter the real part: ";
        input >> t.x;
        cout << "Enter the imaginary part: ";
        input >> t.y;
        return input;
    }

    // Friend function for output (overloading << operator)
    friend ostream& operator<<(ostream &output, complex &t) {
        output << t.x << " + " << t.y << "i\n";
        return output;
    }
};

// Overloading + operator to add two complex numbers
complex complex::operator+(complex c) {
    complex temp;
    temp.x = x + c.x;  // Add real parts
    temp.y = y + c.y;  // Add imaginary parts
    return temp;
}

// Overloading * operator to multiply two complex numbers
complex complex::operator*(complex c) {
    complex temp2;
    temp2.x = (x * c.x) - (y * c.y);  // Real part of the product
    temp2.y = (y * c.x) + (x * c.y);  // Imaginary part of the product
    return temp2;
}

int main() {
    complex c1, c2, c3, c4;

    // Display default values (initialized by default constructor)
    cout << "Default constructor value = \n";
    cout << c1;

    // Get input for the first complex number
    cout << "\nEnter the 1st number\n";
    cin >> c1;

    // Get input for the second complex number
    cout << "\nEnter the 2nd number\n";
    cin >> c2;

    // Add the two complex numbers
    c3 = c1 + c2;

    // Multiply the two complex numbers
    c4 = c1 * c2;

    // Display results
    cout << "\nThe first number is: " << c1;
    cout << "\nThe second number is: " << c2;
    cout << "\nThe addition is: " << c3;
    cout << "\nThe multiplication is: " << c4;

    return 0;
}
