using System;
using System.Collections.Generic;
using System.Linq;

class Expense
{
    public string Description { get; set; }
    public double Amount { get; set; }
    public string Category { get; set; }
    public DateTime Date { get; set; }
}

class expense
{
    static List<Expense> expenses = new List<Expense>();

    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Expense Tracker");
            Console.WriteLine("1. Add Expense");
            Console.WriteLine("2. View Expenses");
            Console.WriteLine("3. Generate Report");
            Console.WriteLine("4. Exit");
            Console.Write("Enter your choice (1-4): ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1":
                    AddExpense();
                    break;
                case "2":
                    ViewExpenses();
                    break;
                case "3":
                    GenerateReport();
                    break;
                case "4":
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

    static void AddExpense()
    {
        Console.WriteLine("Add Expense");
        Console.Write("Description: ");
        string description = Console.ReadLine();
        Console.Write("Amount: ");
        double amount = double.Parse(Console.ReadLine());
        Console.Write("Category: ");
        string category = Console.ReadLine();
        Console.Write("Date (dd/mm/yyyy): ");
        DateTime date = DateTime.Parse(Console.ReadLine());

        Expense expense = new Expense
        {
            Description = description,
            Amount = amount,
            Category = category,
            Date = date
        };

        expenses.Add(expense);
        Console.WriteLine("Expense added successfully.");
    }

    static void ViewExpenses()
    {
        Console.WriteLine("View Expenses");

        if (expenses.Count == 0)
        {
            Console.WriteLine("No expenses found.");
        }
        else
        {
            foreach (var expense in expenses)
            {
                Console.WriteLine($"Description: {expense.Description}");
                Console.WriteLine($"Amount: {expense.Amount:C2}");
                Console.WriteLine($"Category: {expense.Category}");
                Console.WriteLine($"Date: {expense.Date.ToShortDateString()}");
                Console.WriteLine();
            }
        }
    }

    static void GenerateReport()
    {
        Console.WriteLine("Generate Report");

        if (expenses.Count == 0)
        {
            Console.WriteLine("No expenses found.");
        }
        else
        {
            Console.WriteLine("Expense Report:");
            Console.WriteLine();

            var expenseCategories = expenses.Select(e => e.Category).Distinct();
            foreach (var category in expenseCategories)
            {
                var categoryExpenses = expenses.Where(e => e.Category == category);
                double totalAmount = categoryExpenses.Sum(e => e.Amount);

                Console.WriteLine($"Category: {category}");
                Console.WriteLine($"Total Expenses: {totalAmount:C2}");
                Console.WriteLine();
            }
        }
    }
}
