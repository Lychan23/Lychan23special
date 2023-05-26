//C++ program to find LCM
#include <iostream>
using namespace std;

int main()
{
   int num1, num2, maxValue;

   cout << "Enter two numbers: " << endl;
   cin >> num1 >> num2;

   maxValue = (num1 > num2) ? num1 : num2;

   while(1)
   {
      //condition of LCM
      if((maxValue % num1 == 0) && (maxValue % num2 == 0))
      {
         cout << "LCM: " << maxValue << endl;
         break;
      }
      ++maxValue;
   }
   return 0;
}
