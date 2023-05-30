#include <iostream>
#include <map>
#include <string>

using namespace std;

// Forward declaration of classes
class Room;
class Item;

// Item class
class Item {
public:
    Item(const string& name, const string& description) : name(name), description(description) {}

    string getName() const {
        return name;
    }

    string getDescription() const {
        return description;
    }

private:
    string name;
    string description;
};

// Room class
class Room {
public:
    Room(const string& name, const string& description) : name(name), description(description) {}

    void addItem(Item* item) {
        items[item->getName()] = item;
    }

    void removeItem(const string& itemName) {
        items.erase(itemName);
    }

    string getName() const {
        return name;
    }

    string getDescription() const {
        return description;
    }

    const map<string, Item*>& getItems() const {
        return items;
    }

private:
    string name;
    string description;
    map<string, Item*> items;
};

// Game class
class Game {
public:
    Game() {
        createRooms();
        createItems();
    }

    void play() {
        cout << "Welcome to the Text Adventure Game!\n";
        cout << "Type 'help' for a list of commands.\n";

        currentRoom = rooms["entrance"];

        while (true) {
            cout << "\n";
            cout << currentRoom->getDescription() << "\n";
            cout << "What would you like to do? ";
            string command;
            getline(cin, command);

            if (command == "help") {
                printHelp();
            } else if (command == "look") {
                printRoomItems();
            } else if (command.substr(0, 4) == "take") {
                string itemName = command.substr(5);
                takeItem(itemName);
            } else if (command.substr(0, 4) == "drop") {
                string itemName = command.substr(5);
                dropItem(itemName);
            } else if (command.substr(0, 4) == "goto") {
                string roomName = command.substr(5);
                goToRoom(roomName);
            } else if (command == "quit") {
                cout << "Goodbye!\n";
                break;
            } else {
                cout << "Invalid command. Type 'help' for a list of commands.\n";
            }
        }
    }

private:
    Room* currentRoom;
    map<string, Room*> rooms;
    map<string, Item*> items;

    void createRooms() {
        Room* entrance = new Room("entrance", "You are standing at the entrance of a mysterious castle.");
        Room* hallway = new Room("hallway", "You are in a dimly lit hallway.");
        Room* courtyard = new Room("courtyard", "You are in a spacious courtyard.");

        entrance->addItem(new Item("key", "A rusty old key."));
        hallway->addItem(new Item("lantern", "An old lantern."));
        courtyard->addItem(new Item("sword", "A sharp sword."));

        rooms["entrance"] = entrance;
        rooms["hallway"] = hallway;
        rooms["courtyard"] = courtyard;
    }

    void createItems() {
        // You can add more items here if you like
    }

    void printHelp() {
        cout << "Available commands:\n";
        cout << "help - Display the list of commands.\n";
        cout << "look - Examine the items in the current room.\n";
        cout << "take <item> - Take an item from the current room.\n";
        cout << "drop <item> - Drop an item from your inventory.\n";
        cout << "goto <room> - Move to a different room.\n";
        cout << "quit - Quit the game.\n";
    }

    void printRoomItems() {
        cout << "Items in the room:\n";
        const map<string, Item*>& roomItems = currentRoom->getItems();

        if (roomItems.empty()) {
            cout << "None\n";
        } else {
            for (const auto& item : roomItems) {
                cout << "- " << item.first << ": " << item.second->getDescription() << "\n";
            }
        }
    }

    void takeItem(const string& itemName) {
        Item* item = currentRoom->getItems()[itemName];

        if (item) {
            items[itemName] = item;
            currentRoom->removeItem(itemName);
            cout << "You picked up the " << itemName << ".\n";
        } else {
            cout << "That item is not in the room.\n";
        }
    }

    void dropItem(const string& itemName) {
        Item* item = items[itemName];

        if (item) {
            currentRoom->addItem(item);
            items.erase(itemName);
            cout << "You dropped the " << itemName << ".\n";
        } else {
            cout << "You don't have that item.\n";
        }
    }

    void goToRoom(const string& roomName) {
        Room* room = rooms[roomName];

        if (room) {
            currentRoom = room;
            cout << "You are now in the " << roomName << ".\n";
        } else {
            cout << "That room does not exist.\n";
        }
    }
};

int main() {
    Game game;
    game.play();

    return 0;
}
