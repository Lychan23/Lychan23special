//C++ program for palindrome numbers
#include<iostream>
using namespace std;

int main()
{
   int num, reverse = 0, remainder, temp;
   // reverse is used to store to reverse number
   cout << "Enter the number: ";
   cin >> num;

   temp = num; // original number is stored in temp variable

   while( temp != 0)
   {
      remainder = temp % 10;
      reverse = reverse * 10 + remainder;
      temp = temp / 10;
   }

   cout << "Reversed number: " << reverse << endl;

   if (num == reverse) // checking whether num is equal to reverse
      cout << "\n" << num << " is a palindrome number." << endl;
   else
      cout << "\n" << num << " is not a palindrome number." << endl;
   return 0;
}d
