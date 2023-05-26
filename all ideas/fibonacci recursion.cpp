//C++ program to display Fibonacci series using recursion

#include<iostream>
using namespace std;

int fibonacci(int n);  //function declaration

int main()
{
   int num, fibNum, i;

   //Enter the total number in series
   cout << "Enter the number of terms: ";
   cin >> num;

   fibNum = 0;

   cout << "\nFibonacci Series: ";

   for(i = 1; i <= num; i++)
   {
      cout << " " <<fibonacci(fibNum); //calling recursive function
      fibNum++;
   }

   cout << "\n";
   return 0;
}

//recursive function for Fibonacci series
int fibonacci(int n)
{
   if(n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
    return(fibonacci(n-1) + fibonacci(n-2)); //calling itself
}
