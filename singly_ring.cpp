#include<iostream>
using namespace std;

// Node structure for a singly circular linked list
struct node {
    int data;
    node *next;
};

// Class for a singly circular linked list
class singularcirculylinklist {
private:
    node* head;  // Pointer to the head of the linked list

public:
    // Constructor to initialize the linked list
    singularcirculylinklist() {
        head = NULL;  // Initialize head to NULL
    }

    // Function to create a new node with given data
    node* create_node(int data) {
        node* link_node = new node();  // Create a new node
        link_node->data = data;  // Set the data of the node
        return link_node;
    }

    // Function to get the tail (last node) of the linked list
    node* get_tail() {
        node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        return tail;
    }

    // Function to add a new node with given data to the tail of the linked list
    void add_node_to_tail(int data) {
        if (head == NULL) {
            // If the linked list is empty, create a node and make it circular
            head = create_node(data);
            head->next = head;
            return;
        }
        node* tail = get_tail();
        node* link_node = create_node(data);
        link_node->next = tail->next;
        tail->next = link_node;
    }

    // Function to print the linked list
    void print() {
        if (head == NULL) {
            return;  // If the linked list is empty, return
        }
        node* iter = head;  // Start from the head
        do {
            cout << iter->data << endl;  // Print the data of the current node
            iter = iter->next;  // Move to the next node
        } while (iter != head);  // Continue until we reach the head again
    }

    // Function to search for a node with a given key in the linked list
    node* search_node(int key) {
        node* link_node = head;
        while (link_node->data != key) {
            link_node = link_node->next;
            // You need to add a condition to break the loop if you don't want it to run indefinitely.
            // For example, you can check if link_node is equal to the head again.
        }
        return link_node;
    }
};

int main() {
    singularcirculylinklist ring;
    ring.add_node_to_tail(10);
    ring.add_node_to_tail(11);
    ring.add_node_to_tail(12);
    ring.print();  // Print the circular linked list
    return 0;
}
