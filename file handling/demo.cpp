#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file;

    // Open the file in both write and read mode
    file.open("example.txt", ios::out | ios::trunc); // First open for writing (truncate the file if it exists)
    
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return 1; // Exit if file couldn't be opened
    }

    // Writing to the file
    file << "Hello, World!" << endl;
    
    // Close the file after writing
    file.close();

    // Re-open the file in read mode
    file.open("example.txt", ios::in);
    
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return 1; // Exit if file couldn't be opened
    }

    // Reading from the file
    string content;
    while (getline(file, content)) {
        cout << "Content read from the file: " << content << endl;
    }

    // Close the file after reading
    file.close();

    return 0;
}

