//C++ program to find GCD or HCF using while loop
#include <iostream>
using namespace std;

int main()
{
   int x, y, temp, gcd;

   cout << "Enter two integer values:" << endl;
   cin >> x >> y;

   //while loop for calculation of GCD
   while (y != 0)
   {
      temp = y;
      y = x % y;
      x = temp;
   }

   gcd = x;
   cout << "\nGCD of given numbers: " << gcd << endl;

   return 0;
}
