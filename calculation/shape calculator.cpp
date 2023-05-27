#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int choice;
    double length, width, sideLength, baseLength, height, radius, result;
    const double pi = 3.14;

    cout << "Welcome to the Shape Calculator!\n\n";
    cout << "Please select a shape to calculate the area or volume of:\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Circle\n";
    cout << "5. Sphere\n";
    cout << "6. Cylinder\n";
    cout << "7. Cube\n\n";
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nEnter the length of a side of the square: ";
            cin >> sideLength;
            result = pow(sideLength, 2);
            cout << "\nThe area of the square is " << result << endl;
            break;
        case 2:
            cout << "\nEnter the length and width of the rectangle (separated by a space): ";
            cin >> length >> width;
            result = length * width;
            cout << "\nThe area of the rectangle is " << result << endl;
            break;
        case 3:
            cout << "\nEnter the base length and height of the triangle (separated by a space): ";
            cin >> baseLength >> height;
            result = 0.5 * baseLength * height;
            cout << "\nThe area of the triangle is " << result << endl;
            break;
        case 4:
            cout << "\nEnter the radius of the circle: ";
            cin >> radius;
            result = pi * pow(radius, 2);
            cout << "\nThe area of the circle is " << result << endl;
            break;
        case 5:
            cout << "\nEnter the radius of the sphere: ";
            cin >> radius;
            cout << "Surface area of sphere = " << 4 * pi * pow(radius, 2) << endl;
            cout << "Volume of sphere = " << 4.0 / 3.0 * pi * pow(radius, 3) << endl;
            break;
        case 6:
            cout << "\nEnter the radius of the base of the cylinder: ";
            cin >> radius;
            cout << "Enter the height of the cylinder: ";
            cin >> height;
            cout << "Surface area of cylinder = " << 2 * pi * radius * height + 2 * pi * pow(radius, 2) << endl;
            cout << "Volume of cylinder = " << pi * pow(radius, 2) * height << endl;
            break;
        case 7:
            cout << "\nEnter the length of a side of the cube: ";
            cin >> sideLength;
            cout << "Surface area of cube = " << 6 * pow(sideLength, 2) << endl;
            cout << "Volume of cube = " << pow(sideLength, 3) << endl;
            break;
        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 7.\n";
            break;
    }

    return 0;
}
