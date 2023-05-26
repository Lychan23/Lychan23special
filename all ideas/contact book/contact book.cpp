#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
};

// Function to display the main menu
void displayMenu() {
    cout << "Contact Book\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Search Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a contact
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin >> ws, newContact.name);
    cout << "Enter phone number: ";
    getline(cin >> ws, newContact.phone);
    contacts.push_back(newContact);
    cout << "Contact added successfully!\n";
}

// Function to view all contacts
void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    cout << "Contacts:\n";
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << endl;
        cout << "Phone: " << contact.phone << endl;
        cout << "----------------------\n";
    }
}

// Function to search for a contact by name
void searchContact(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    string searchName;
    cout << "Enter the name to search: ";
    getline(cin >> ws, searchName);

    auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        return contact.name == searchName;
    });

    if (it != contacts.end()) {
        cout << "Contact found:\n";
        cout << "Name: " << it->name << endl;
        cout << "Phone: " << it->phone << endl;
    } else {
        cout << "Contact not found.\n";
    }
}

// Function to delete a contact by name
void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    string deleteName;
    cout << "Enter the name to delete: ";
    getline(cin >> ws, deleteName);

    auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
        return contact.name == deleteName;
    });

    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "Contact deleted successfully!\n";
    } else {
        cout << "Contact not found.\n";
    }
}

// Function to save contacts to a file
void saveContactsToFile(const vector<Contact>& contacts, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& contact : contacts) {
            file << contact.name << endl;
            file << contact.phone << endl;
        }
        file.close();
        cout << "Contacts saved to file.\n";
    } else {
        cout << "Unable to save contacts to file.\n";
    }
}

// Function to load contacts from a file
void loadContactsFromFile(vector<Contact>& contacts, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        contacts.clear();
        string name, phone;
        while (getline(file, name) && getline(file, phone)) {
            Contact contact;
            contact.name = name;
            contact.phone = phone;
            contacts.push_back(contact);
        }
        file.close();
        cout << "Contacts loaded from file.\n";
    } else {
        cout << "No existing contacts file found.\n";
    }
}

int main() {
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    loadContactsFromFile(contacts, filename);

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                saveContactsToFile(contacts, filename);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }
}

