#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Function to perform XOR encryption or decryption
void xorEncryptDecrypt(const string& inputFileName, const string& outputFileName, const string& password) {
    ifstream inputFile(inputFileName, ios::binary);
    ofstream outputFile(outputFileName, ios::binary);

    if (!inputFile.is_open()) {
        throw runtime_error("Error opening input file: " + inputFileName);
    }

    if (!outputFile.is_open()) {
        throw runtime_error("Error opening output file: " + outputFileName);
    }

    char inputByte;
    size_t passwordIndex = 0;
    while (inputFile.get(inputByte)) {
        char encryptedByte = inputByte ^ password[passwordIndex];
        outputFile.put(encryptedByte);

        passwordIndex = (passwordIndex + 1) % password.length();
    }

    inputFile.close();
    outputFile.close();

    cout << "File encrypted/decrypted successfully." << endl;
}

int main() {
    int choice;
    string inputFileName, outputFileName, password, directoryPath;

    cout << "File Encryption/Decryption Program" << endl;
    cout << "1. Encrypt File" << endl;
    cout << "2. Decrypt File" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << "Invalid choice. Exiting program." << endl;
        return 0;
    }

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    cout << "Enter the password: ";
    cin >> password;

    if (inputFileName.empty() || outputFileName.empty() || password.empty()) {
        cout << "Invalid input. Exiting program." << endl;
        return 0;
    }

    try {
        xorEncryptDecrypt(inputFileName, outputFileName, password);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 0;
    }

    cout << "Do you want to save the file in a directory? (Y/N): ";
    char saveDirectoryChoice;
    cin >> saveDirectoryChoice;

    if (saveDirectoryChoice == 'Y' || saveDirectoryChoice == 'y') {
        cout << "Enter the directory path: ";
        cin >> directoryPath;

        string fullOutputFilePath = directoryPath + "/" + outputFileName;
        if (rename(outputFileName.c_str(), fullOutputFilePath.c_str()) != 0) {
            cout << "Error moving the file to the specified directory." << endl;
        } else {
            cout << "File saved in the directory successfully." << endl;
        }
    }

    return 0;
}
