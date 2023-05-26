//C++ program to implement Fibonacci series

#include<iostream>
using namespace std;

int main()
{
   int oldNum, newNum, fibNum, maxNum;

   //Enter maximum number till you want to generate Fibonacci series
   cout << "Enter number: ";
   cin >> maxNum;

   oldNum = 0;
   newNum = 1;
   fibNum = oldNum + newNum;

   cout << "\nFibonacci Series: " << oldNum << " " << newNum;

   //while is true till fibNum is less than maxNum and fibNum is calculated
   while(fibNum <= maxNum)
   {
      cout << " " << fibNum;
      oldNum = newNum;
      newNum = fibNum;
      fibNum = oldNum + newNum;
   }

   cout << "\n";
   return 0;
}
