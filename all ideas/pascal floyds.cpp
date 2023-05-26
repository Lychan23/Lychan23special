//Pascal triangle in C++
#include <iostream>
using namespace std;

int main()
{
   int n, i, j, c = 1, s;

   cout << "Enter number of rows to print in Pascal triangle: ";
   cin >> n;

   //for loop continues till the number of rows entered by the user
   for(i = 0; i < n; i++)
   {
      //for loop to print required number of space
      for(s = 1; s <= n - i; s++)
         cout << " ";

      //for loop to print number in triangle
      for(j = 0; j <= i; j++)
      {
         //first and last value of every row is 1
         if (j==0 || i==0)
            c = 1;
         else
            c = c *( i - j + 1) / j;

         cout << c << " ";
      }
      cout << endl;
   }

   return 0;
}
