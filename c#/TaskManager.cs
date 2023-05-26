using System;
using System.Collections.Generic;
using System.Linq;

class Task
{
    public string Description { get; set; }
    public int Priority { get; set; }
    public DateTime DueDate { get; set; }
    public bool IsComplete { get; set; }
}

class managertask
{
    static List<Task> tasks = new List<Task>();

    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Task Manager");
            Console.WriteLine("1. Add Task");
            Console.WriteLine("2. View Tasks");
            Console.WriteLine("3. Mark Task as Complete");
            Console.WriteLine("4. Sort Tasks");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice (1-5): ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1":
                    AddTask();
                    break;
                case "2":
                    ViewTasks();
                    break;
                case "3":
                    MarkTaskAsComplete();
                    break;
                case "4":
                    SortTasks();
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

    static void AddTask()
    {
        Console.WriteLine("Add Task");
        Console.Write("Description: ");
        string description = Console.ReadLine();
        Console.Write("Priority (1-5, where 1 is the highest): ");
        int priority = int.Parse(Console.ReadLine());
        Console.Write("Due Date (dd/mm/yyyy): ");
        DateTime dueDate = DateTime.Parse(Console.ReadLine());

        Task task = new Task
        {
            Description = description,
            Priority = priority,
            DueDate = dueDate,
            IsComplete = false
        };

        tasks.Add(task);
        Console.WriteLine("Task added successfully.");
    }

    static void ViewTasks()
    {
        Console.WriteLine("View Tasks");

        if (tasks.Count == 0)
        {
            Console.WriteLine("No tasks found.");
        }
        else
        {
            foreach (var task in tasks)
            {
                Console.WriteLine($"Description: {task.Description}");
                Console.WriteLine($"Priority: {task.Priority}");
                Console.WriteLine($"Due Date: {task.DueDate.ToShortDateString()}");
                Console.WriteLine($"Status: {(task.IsComplete ? "Complete" : "Incomplete")}");
                Console.WriteLine();
            }
        }
    }

    static void MarkTaskAsComplete()
    {
        Console.WriteLine("Mark Task as Complete");
        Console.Write("Enter the description of the task to mark as complete: ");
        string description = Console.ReadLine();

        Task task = tasks.Find(t => t.Description == description);
        if (task != null)
        {
            task.IsComplete = true;
            Console.WriteLine("Task marked as complete.");
        }
        else
        {
            Console.WriteLine("Task not found.");
        }
    }

    static void SortTasks()
    {
        Console.WriteLine("Sort Tasks");
        Console.WriteLine("1. Sort by Priority");
        Console.WriteLine("2. Sort by Due Date");
        Console.Write("Enter your choice (1-2): ");
        string choice = Console.ReadLine();
        Console.WriteLine();

        switch (choice)
        {
            case "1":
                tasks = tasks.OrderBy(t => t.Priority).ToList();
                Console.WriteLine("Tasks sorted by priority.");
                break;
            case "2":
                tasks = tasks.OrderBy(t => t.DueDate).ToList();
                Console.WriteLine("Tasks sorted by due date.");
                break;
            default:
                Console.WriteLine("Invalid choice.");
                break;
        }
    }
}
