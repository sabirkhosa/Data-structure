#include<iostream>
using namespace std;

class stack {
private:
    int *arr;  // Array to store the stack elements
    int *top, *n;  // Pointers for the top of the stack and the end of the array
    int s;  // Size of the stack

public:
    // Constructor to initialize the stack with a given size
    stack(int size) {
        top = NULL;  // Initialize top to NULL
        n = NULL;  // Initialize n to NULL
        arr = new int[size];  // Create an array of given size
        n = arr;  // Set n to the start of the array
        s = size;  // Set the size of the stack
    }

    // Function to check if the stack is empty
    bool is_empty() {
        return (top == NULL);
    }

    // Function to check if the stack is full
    bool is_full() {
        return (top == n + (s - 1));
    }

    // Function to push a value onto the stack
    void push(int val) {
        if (is_full()) {
            cout << "Stack overflow" << endl;
        } else {
            if (top == NULL) {
                top = arr;
                *top = val;
            } else {
                top = top + 1;
                *top = val;
            }
        }
    }

    // Function to pop a value from the stack
    void pop() {
        if (is_empty()) {
            cout << "Stack underflow" << endl;
        } else {
            if (top == n) {
                int *a = top;
                top = NULL;
                cout << *a << endl;
            } else {
                int *temp = top;
                top = top - 1;
                cout << *temp << endl;
            }
        }
    }

    // Function to get the top element of the stack
    int get_top() {
        return *top;
    }
};

int main() {
    stack obj(7);

    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);
    obj.push(7);

    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();

    return 0;
}
