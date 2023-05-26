using System;
using System.Collections.Generic;
using System.Linq;

class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public bool IsCheckedOut { get; set; }
}

class libman
{
    static List<Book> books = new List<Book>();

    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Library Management System");
            Console.WriteLine("1. Add Book");
            Console.WriteLine("2. Search Books");
            Console.WriteLine("3. Check Out Book");
            Console.WriteLine("4. Return Book");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice (1-5): ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1":
                    AddBook();
                    break;
                case "2":
                    SearchBooks();
                    break;
                case "3":
                    CheckOutBook();
                    break;
                case "4":
                    ReturnBook();
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

    static void AddBook()
    {
        Console.WriteLine("Add Book");
        Console.Write("Title: ");
        string title = Console.ReadLine();
        Console.Write("Author: ");
        string author = Console.ReadLine();

        Book book = new Book
        {
            Title = title,
            Author = author,
            IsCheckedOut = false
        };

        books.Add(book);
        Console.WriteLine("Book added successfully.");
    }

    static void SearchBooks()
    {
        Console.WriteLine("Search Books");
        Console.WriteLine("1. Search by Title");
        Console.WriteLine("2. Search by Author");
        Console.Write("Enter your choice (1-2): ");
        string choice = Console.ReadLine();
        Console.WriteLine();

        switch (choice)
        {
            case "1":
                Console.Write("Enter the title to search: ");
                string title = Console.ReadLine();
                Console.WriteLine();

                var titleResults = books.Where(b => b.Title.ToLower().Contains(title.ToLower())).ToList();
                if (titleResults.Count == 0)
                {
                    Console.WriteLine("No books found with the given title.");
                }
                else
                {
                    Console.WriteLine("Search Results:");
                    foreach (var book in titleResults)
                    {
                        Console.WriteLine($"Title: {book.Title}");
                        Console.WriteLine($"Author: {book.Author}");
                        Console.WriteLine($"Status: {(book.IsCheckedOut ? "Checked Out" : "Available")}");
                        Console.WriteLine();
                    }
                }
                break;

            case "2":
                Console.Write("Enter the author to search: ");
                string author = Console.ReadLine();
                Console.WriteLine();

                var authorResults = books.Where(b => b.Author.ToLower().Contains(author.ToLower())).ToList();
                if (authorResults.Count == 0)
                {
                    Console.WriteLine("No books found with the given author.");
                }
                else
                {
                    Console.WriteLine("Search Results:");
                    foreach (var book in authorResults)
                    {
                        Console.WriteLine($"Title: {book.Title}");
                        Console.WriteLine($"Author: {book.Author}");
                        Console.WriteLine($"Status: {(book.IsCheckedOut ? "Checked Out" : "Available")}");
                        Console.WriteLine();
                    }
                }
                break;

            default:
                Console.WriteLine("Invalid choice.");
                break;
        }
    }

    static void CheckOutBook()
    {
        Console.WriteLine("Check Out Book");
        Console.Write("Enter the title of the book to check out: ");
        string title = Console.ReadLine();
        Console.WriteLine();

        var book = books.FirstOrDefault(b => b.Title.ToLower() == title.ToLower());
        if (book == null)
        {
            Console.WriteLine("Book not found.");
        }
        else if (book.IsCheckedOut)
        {
            Console.WriteLine("Book is already checked out.");
        }
        else
        {
            book.IsCheckedOut = true;
            Console.WriteLine("Book checked out successfully.");
        }
    }

    static void ReturnBook()
    {
        Console.WriteLine("Return Book");
        Console.Write("Enter the title of the book to return: ");
        string title = Console.ReadLine();
        Console.WriteLine();

        var book = books.FirstOrDefault(b => b.Title.ToLower() == title.ToLower());
        if (book == null)
        {
            Console.WriteLine("Book not found.");
        }
        else if (!book.IsCheckedOut)
        {
            Console.WriteLine("Book is already available.");
        }
        else
        {
            book.IsCheckedOut = false;
            Console.WriteLine("Book returned successfully.");
        }
    }
}
