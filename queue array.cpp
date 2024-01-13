#include<iostream>
using namespace std;

class queue{
private:
    int size;
    int *arr;
    int *front;
    int *rear;
    int len;

public:
    // Constructor to initialize the queue with a given size
    queue(int s){
        size = s;
        arr = new int[size];
        len = 0;
        front = rear = NULL;
        rear = arr;
        front = arr;
    }

    // Function to check if the queue is empty
    bool is_empty(){
        return len == 0;
    }

    // Function to check if the queue is full
    bool is_full(){
        return len == size;
    }

    // Function to enqueue (add) an element to the queue
    void enqueue(int val){
        if(is_full()){
            cout << "Overflow: Queue is full." << endl;
            return;
        }
        if(is_empty()){
            *rear = val;
            len++;
        } else {
            rear++;
            *rear = val;
            len++;
        }
    }

    // Function to dequeue (remove) an element from the queue
    int dequeue(){
        if(is_empty()){
            cout << "Underflow: Queue is empty." << endl;
            return 10; // Returning some default value, you may choose another strategy
        } else {
            front++;
            len--;
            return *front;
        }
        front = arr; // This line seems unnecessary and can be removed
    }

    // Function to peek at the front element of the queue without removing it
    int peek(){
        if(is_empty()){
            cout << "Underflow: Queue is empty." << endl;
            // You may choose another strategy, like returning a special value or throwing an exception
        } else {
            return *front;
        }
    }
};

int main(){
    // Example usage of the queue
    queue obj(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);

    cout << obj.dequeue() << endl;
    cout << obj.dequeue() << endl;
    cout << obj.dequeue() << endl;
    cout << obj.dequeue() << endl;

    // Uncommenting the line below will result in an underflow message
    // cout << obj.dequeue() << endl;

    // Uncommenting the line below will result in an underflow message
    // cout << obj.peek() << endl;

    return 0;
}
