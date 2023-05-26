#include <iostream>
using namespace std;

int main ()
{
   int num1, num2, i, j, temp, flag;

   cout << "Enter two numbers(intervals): " << endl;
   cin >> num1 >> num2;

   //swapping numbers if first number is greater than second one
   if (num1 > num2)
   {
      temp = num1;
      num1 = num2;
      num2 = temp;
   }

   cout << "\nPrime numbers between " << num1 << " and " << num2 << " are:" << endl;
   // Displaying prime number between num1 and num2
   for (i = num1 + 1; i < num2; ++i)
   {
      flag = 0; //flag is set to 0
      for (j = 2; j <= i/2; ++j)
      {
         if (i % j == 0)
         {
            flag = 1;
            break;
         }
      }
      if (flag == 0) //if flag == 0, then display i
         cout << i << "\t";
   }
   cout << "\n\n";
   return 0;
}
