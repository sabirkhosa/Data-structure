#include<iostream>
#include<cmath>
using namespace std;

// Structure for a linked list node
struct node {
    int data;
    node* next;
};

// Class representing a linked list
class List {
private:
    node* head;

public:
    // Constructor to initialize the linked list with a null head
    List() {
        head = NULL;
    }

    // Function to create a new node with given data
    node* get_new_node(int data) {
        node* link_node = new node();
        link_node->data = data;
        link_node->next = NULL;
        return link_node;
    }

    // Function to add a new node to the tail of the linked list
    void add_link_node_to_tail(int data) {
        if (head == NULL) {
            head = get_new_node(data);
            return;
        }

        node* data_node = get_new_node(data);
        node* tail = get_tail(head);
        tail->next = data_node;
    }

    // Function to get the head of the linked list
    node* get_head() {
        return head;
    }

    // Function to get the tail of the linked list
    node* get_tail(node* head) {
        node* tail_hunter = head;
        if (tail_hunter->next == NULL) {
            return tail_hunter;
        }
        get_tail(head->next);
    }

    // Function to calculate the length of the linked list
    int calculate_len(node* head, int sum) {
        node* itera1 = head;
        if (itera1->next == NULL) {
            cout << endl;
            return sum;
        } else {
            calculate_len((head->next), sum + 1);
        }
    }

    // Function to print the linked list
    void print(node* head) {
        node* itera = head;
        if (itera->next == NULL) {
            cout << endl;
            return;
        }
        cout << itera->data;
        print(head->next);
        cout << itera->data;
    }
};

int main() {
    List l1, l2;
    int sum = 0;

    // Add elements to the linked list l1
    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(4);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(5);
    l1.add_link_node_to_tail(3);

    // Print the linked list l1
    l1.print(l1.get_head());

    // Calculate and print the length of the linked list l1
    cout << l1.calculate_len(l1.get_head(), sum);

    return 0;
}
