//C++ program to find area of the circle using function
#include <iostream>
using namespace std;

//function declaration
float areaOfCircle(float radius_circle);

int main() {
   float radius;

   // take radius as input
   cout << "Enter the radius of circle: ";
   cin >> radius;

   cout << "Area of circle: " << areaOfCircle(radius) << endl;

   return 0;
}

// function definition to calculate area of circle
float areaOfCircle(float radius_circle)
{
   float area_circle;
   area_circle = 3.14 * radius_circle * radius_circle;

   return area_circle; //return area
 }
