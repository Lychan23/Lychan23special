using System;

class newcs
{
    static void Main()
    {
        Console.WriteLine("Welcome to My Console App!");

        // Prompt the user for input
        Console.Write("Please enter your name: ");
        string name = Console.ReadLine();

        // Display a personalized greeting
        Console.WriteLine($"Hello, {name}!");

        // Wait for user input before exiting the program
        Console.WriteLine("Press any key to exit...");
        Console.ReadKey();
    }
}
