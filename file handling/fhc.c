#include <stdio.h>

int main() {
    FILE *filePointer;
    char dataToWrite[50] = "Hello, World!";
    char dataToRead[50];

    // Writing to a file
    filePointer = fopen("example2.txt", "w"); // Open file in write mode
    if (filePointer == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1; // Exit if file couldn't be opened
    }
    fprintf(filePointer, "%s", dataToWrite); // Write to the file
    fclose(filePointer); // Close the file after writing

    // Reading from a file
    filePointer = fopen("example2.txt", "r"); // Open file in read mode
    if (filePointer == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1; // Exit if file couldn't be opened
    }
    fscanf(filePointer, "%s", dataToRead); // Read the file content
    printf("Data read from the file: %s\n", dataToRead);
    fclose(filePointer); // Close the file after reading

    return 0;
}
