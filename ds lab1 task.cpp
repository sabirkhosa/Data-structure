#include<iostream>
using namespace std;

// Function to calculate the length of a string
int getlength(char *ch, char *ptr, int count) {
    // Check if the current character is the null terminator '\0'
    if (*ptr == '\0') {
        // Return the count as the length of the string
        return count;
    } else {
        // Move to the next character in the string and increment the count
        ptr++;
        count = count + 1;

        // Recursively call the function to process the next character
        return getlength(ch, ptr, count);
    }
}

// Function to find the position of the decimal point in a string
int finddecimal(char *ch, char *ptr, int index) {
    // Check if the current character is a decimal point '.'
    if (*ptr == '.') {
        // Return the index as the position of the decimal point
        return index;
    } else {
        // Move to the next character in the string and increment the index
        ptr++;
        index = index + 1;

        // Recursively call the function to find the decimal point
        return finddecimal(ch, ptr, index);
    }
}

int main() {
    // Define a character array (string)
    char *ch = "22222.222222222";
    char *ptr = NULL;
    ptr = ch;
    int x, y; // Variables to store the length and decimal position
    int count = 0; // Counter for length calculation
    int index = 1; // Index for decimal position calculation

    // Call the functions to get the length and decimal position
    x = getlength(ch, ptr, count);
    y = finddecimal(ch, ptr, index);

    // Print the results
    cout << "Length is: " << x << endl;
    cout << "Decimal is at position: " << y << endl;

    return 0;
}
