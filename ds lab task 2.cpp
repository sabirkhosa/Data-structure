#include<iostream>
using namespace std;

int main() {
    // Define the size of the array
    int size = 6;

    // Create a dynamic array of integers
    int *arr = new int[size];
    int *ptr = NULL;
    int *ptr1 = NULL;
    ptr = arr;

    // Input values into the array
    cout << "Enter the values of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> *ptr;
        ptr++;
    }

    // Print the input array
    cout << "Array list: ";
    ptr = arr;
    for (int i = 0; i < size; i++) {
        cout << *ptr << " ";
        ptr++;
    }

    // Set the target sum to find
    int target = 15;
    ptr1 = ptr = arr;
    int sum;
    int flag = 0;

    // Iterate through the array to find two elements whose sum is equal to the target
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum = *ptr + *ptr1;
            if (sum == target) {
                flag = 1;
                break;
            }
            ptr1++;
        }
        if (flag == 1) {
            break;
        }
        ptr1 = arr;
        ptr++;
    }

    // Print the output, i.e., the two elements whose sum is equal to the target
    cout << endl << "Output: " << *ptr << ", " << *ptr1 << endl;

    // Deallocate memory for the dynamic array
    delete[] arr;

    return 0;
}
