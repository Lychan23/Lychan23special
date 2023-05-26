#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string getRandomResponse(const vector<string>& responses) {
    int randomIndex = rand() % responses.size();
    return responses[randomIndex];
}

string getResponse(const string& query) {
    string response;

    // Rule-based responses
    if (toLowerCase(query) == "hello") {
        response = "Hello! How can I assist you?";
    } else if (toLowerCase(query) == "how are you?") {
        response = "I'm good. Thanks for asking!";
    } else if (toLowerCase(query) == "goodbye") {
        response = "Goodbye! Have a great day!";
    } else if (toLowerCase(query) == "what's your name?") {
        response = "My name is Chatbot. Nice to meet you!";
    } else if (toLowerCase(query) == "what time is it?") {
        time_t now = time(0);
        string timeString = ctime(&now);
        response = "It is currently " + timeString;
    } else {
        // Default response
	vector<string> defaultResponses;
		defaultResponses.push_back("I'm sorry, I don't understand. Can you please rephrase your query?");
		defaultResponses.push_back("I'm still learning. Can you ask me something else?");
		defaultResponses.push_back("I'm afraid I can't help with that. Is there anything else you'd like to know?");
		defaultResponses.push_back("I'm processing your query. Please wait a moment.");
		defaultResponses.push_back("I'm here to assist you. How can I help?");
        };
        response = getRandomResponse(defaultResponses);
    }

    return response;
}

int main() {
    cout << "Chatbot: Hello! How can I assist you?" << endl;

    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator

    while (true) {
        string userQuery;
        cout << "User: ";
        getline(cin, userQuery);

        string botResponse = getResponse(userQuery);
        cout << "Chatbot: " << botResponse << endl;

        // Exit the loop if the user says goodbye
        if (toLowerCase(userQuery) == "goodbye")
            break;
    }

    return 0;
}

