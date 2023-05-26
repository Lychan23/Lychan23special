//Armstrong number program in C++
#include <iostream>
using namespace std;

int main()
{
   int num, temp, rem, sum = 0;

   cout << "Enter a three digit positive number: ";
   cin >> num;

   temp = num; //storing num into temp for using later in the program

   //while loop for cubing individual digit of num
   while (num != 0)
   {
      rem = num % 10;
      sum += rem * rem * rem;
      num = num / 10;
   }

   //if condition for comparing sum with original number
   if (temp == sum)
      cout << temp << " is an Armstrong number" << endl;
   else
      cout << temp << " is not an Armstrong number" << endl;

   return 0;
} //end main
