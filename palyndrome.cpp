#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int *arr;
    int index = 0;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> index;

    // Dynamically allocate memory for the array
    arr = new int[index];
    
    int *temp = arr;
    int *temp1 = arr;

    // Input elements into the array
    cout << "Enter array elements: ";
    for (int i = 0; i < index; i++) {
        cin >> *temp;
        temp++;
    }

    // Initialize pointers to the beginning and end of the array
    temp1 = arr;
    for (int i = 0; i < index - 1; i++) {
        temp1++;
    }

    // Check if the array is a palindrome
    temp = arr;
    for (int i = 0; i < index / 2; i++) {
        if (*temp == *temp1) {
            // If elements at current positions are equal, move pointers accordingly
            temp1--;
            temp++;
        } else {
            // If elements are not equal, it's not a palindrome
            cout << "Not a palindrome" << endl;
            break;
        }

        if (temp == temp1) {
            // If pointers meet, it's a palindrome
            cout << "Palindrome" << endl;
            break;
        }
    }

    // Deallocate memory
    delete[] arr;

    return 0;
}
