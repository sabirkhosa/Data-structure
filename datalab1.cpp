#include<iostream>
using namespace std;

// Class definition for a dynamic list
class List {
private:
    int *arr;      // Array to store the list elements
public:
    int size, len; // Size of the list and current length
    int *temp, *temp1, *current; // Pointers for temporary operations

    // Constructor to initialize the list
    List() {
        cout << "Enter size: ";
        cin >> size;
        len = 0;
        current = NULL;
        temp = NULL;
        temp1 = NULL;
        arr = new int[size];
        current = arr;

        // Initialize the array with zeros
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
            current++;
        }
        current = 0;
    }

    // Function to insert an element into the list
    void insert(int value) {
        if (len == size) {
            cout << "Array is filled." << endl;
            return;
        } else {
            current = arr + len;
            *current = value;
            len++;
        }
    }

    // Function to add an element at a specified position in the list
    void add(int pos, int val) {
        current = arr;
        temp = current + size - 1;
        temp1 = temp - 1;

        for (int i = 1; i < pos; i++) {
            current++;
        }

        // Shift elements to make space for the new element
        while (temp != current) {
            int a = *temp1;
            *temp1 = *temp;
            *temp = a;
            temp1--;
            temp--;
        }

        *current = val;
    }

    // Function to remove an element from the list
    void remove(int value) {
        current = arr;
        for (int i = 0; i < size; i++) {
            if (value == arr[i]) {
                arr[i] = 0;
            }
        }
    }

    // Function to clear the list
    void clear() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
            current = 0;
            len = 0;
        }
    }

    // Function to print the elements of the list
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    // Create an object of the List class
    List obj;

    // Perform list operations
    obj.insert(3);
    obj.insert(5);
    obj.insert(6);
    obj.insert(9);
    obj.insert(11);
    obj.add(3, 4);
    
    // Uncomment the following lines to test remove and clear functions
    // obj.remove(6);
    // obj.clear();

    // Print the elements of the list
    obj.print();

    return 0;
}
