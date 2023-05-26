using System;

class calculator
{
    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Calculator");
            Console.WriteLine("1. Addition");
            Console.WriteLine("2. Subtraction");
            Console.WriteLine("3. Multiplication");
            Console.WriteLine("4. Division");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice (1-5): ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1":
                    Addition();
                    break;
                case "2":
                    Subtraction();
                    break;
                case "3":
                    Multiplication();
                    break;
                case "4":
                    Division();
                    break;
                case "5":
                    exit = true;
                    Console.WriteLine("Exiting...");
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }

            Console.WriteLine();
        }
    }

    static void Addition()
    {
        Console.WriteLine("Addition");
        Console.Write("Enter the first number: ");
        double num1 = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter the second number: ");
        double num2 = Convert.ToDouble(Console.ReadLine());
        double result = num1 + num2;
        Console.WriteLine($"Result: {result}");
    }

    static void Subtraction()
    {
        Console.WriteLine("Subtraction");
        Console.Write("Enter the first number: ");
        double num1 = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter the second number: ");
        double num2 = Convert.ToDouble(Console.ReadLine());
        double result = num1 - num2;
        Console.WriteLine($"Result: {result}");
    }

    static void Multiplication()
    {
        Console.WriteLine("Multiplication");
        Console.Write("Enter the first number: ");
        double num1 = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter the second number: ");
        double num2 = Convert.ToDouble(Console.ReadLine());
        double result = num1 * num2;
        Console.WriteLine($"Result: {result}");
    }

    static void Division()
    {
        Console.WriteLine("Division");
        Console.Write("Enter the dividend: ");
        double dividend = Convert.ToDouble(Console.ReadLine());
        Console.Write("Enter the divisor: ");
        double divisor = Convert.ToDouble(Console.ReadLine());

        if (divisor == 0)
        {
            Console.WriteLine("Error: Cannot divide by zero.");
        }
        else
        {
            double result = dividend / divisor;
            Console.WriteLine($"Result: {result}");
        }
    }
}
