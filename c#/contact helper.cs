using System;
using System.Collections.Generic;

class Contact
{
    public string Name { get; set; }
    public string PhoneNumber { get; set; }
    public string Email { get; set; }
}

class contact
{
    static List<Contact> contacts = new List<Contact>();

    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("Contact Management System");
            Console.WriteLine("1. Add Contact");
            Console.WriteLine("2. Edit Contact");
            Console.WriteLine("3. Delete Contact");
            Console.WriteLine("4. Search Contacts");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice (1-5): ");

            string choice = Console.ReadLine();
            Console.WriteLine();

            switch (choice)
            {
                case "1":
                    AddContact();
                    break;
                case "2":
                    EditContact();
                    break;
                case "3":
                    DeleteContact();
                    break;
                case "4":
                    SearchContacts();
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

    static void AddContact()
    {
        Console.WriteLine("Add Contact");
        Console.Write("Name: ");
        string name = Console.ReadLine();
        Console.Write("Phone Number: ");
        string phoneNumber = Console.ReadLine();
        Console.Write("Email: ");
        string email = Console.ReadLine();

        Contact contact = new Contact
        {
            Name = name,
            PhoneNumber = phoneNumber,
            Email = email
        };

        contacts.Add(contact);
        Console.WriteLine("Contact added successfully.");
    }

    static void EditContact()
    {
        Console.WriteLine("Edit Contact");
        Console.Write("Enter the name of the contact to edit: ");
        string name = Console.ReadLine();

        Contact contact = contacts.Find(c => c.Name == name);
        if (contact != null)
        {
            Console.Write("New Phone Number: ");
            string phoneNumber = Console.ReadLine();
            Console.Write("New Email: ");
            string email = Console.ReadLine();

            contact.PhoneNumber = phoneNumber;
            contact.Email = email;

            Console.WriteLine("Contact updated successfully.");
        }
        else
        {
            Console.WriteLine("Contact not found.");
        }
    }

    static void DeleteContact()
    {
        Console.WriteLine("Delete Contact");
        Console.Write("Enter the name of the contact to delete: ");
        string name = Console.ReadLine();

        Contact contact = contacts.Find(c => c.Name == name);
        if (contact != null)
        {
            contacts.Remove(contact);
            Console.WriteLine("Contact deleted successfully.");
        }
        else
        {
            Console.WriteLine("Contact not found.");
        }
    }

    static void SearchContacts()
    {
        Console.WriteLine("Search Contacts");
        Console.Write("Enter the name to search: ");
        string name = Console.ReadLine();

        List<Contact> searchResults = contacts.FindAll(c => c.Name.ToLower().Contains(name.ToLower()));
        if (searchResults.Count > 0)
        {
            Console.WriteLine("Search Results:");
            foreach (var contact in searchResults)
            {
                Console.WriteLine($"Name: {contact.Name}");
                Console.WriteLine($"Phone Number: {contact.PhoneNumber}");
                Console.WriteLine($"Email: {contact.Email}");
                Console.WriteLine();
            }
        }
        else
        {
            Console.WriteLine("No contacts found.");
        }
    }
}
