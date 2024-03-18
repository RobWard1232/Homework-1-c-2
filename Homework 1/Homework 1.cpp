#include <iostream>
#include <fstream>

using namespace std;

// Function to display the menu
void renderMenu() {
    cout << "+-------------------------+" << endl << endl;
    cout << "Please enter your 10 names: ";
}

// Function to list names from a file
void list(const string& filePath) {
    // Opens input file
    ifstream inputFile(filePath);

    // Checks if file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    string line;

    // Iterates through input file to find and display guest information, I found this while loop to be very useful.
    while (getline(inputFile, line)) {
        if (line.find("name: ") != string::npos) {
            cout << line << endl;
        }
    }

    inputFile.close();
}

int main() {
    int i = 0;
    string input;
    string names[10];

    // Gets the username using environment variables
    const char* username = getenv("USER");

    // Create a file path using the username
    string filePath = "/users/" + string(username) + "/Desktop/homework/Homework 1/temp.txt";

    // Opens output file in append mode, I found this gives it less room for error.
    ofstream outputFile(filePath, std::ios::app);

    // program loop
    while (true) {
        // Display the menu
        renderMenu();

        // Input loop to get 10 names
        while (i < 10) {
            cin >> names[i];
            cout << ": ";
            i++;
        }

        // Write names to the output file
        for (int j = 0; j < 10; j++) {
            outputFile << "name: " << names[j] << endl;
        }

        // Ask user if they want to see the content of the file
        cout << endl << "Would you like the content of the file? y/n" << endl << ": ";
        cin >> input;

        // If user wants to see the content, call the list function
        if (input == "y" || input == "Y") {
            list(filePath);
            return 0;
        }
    }
}
