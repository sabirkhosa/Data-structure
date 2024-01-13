#include<iostream>
using namespace std;

// Node structure for a singly circular linked list
struct node {
    char data;
    node* next;
};

// Class representing a singly circular linked list
class SinglyCircularLinkList {
private:
    node* head;

public:
    // Constructor to initialize the linked list with a null head
    SinglyCircularLinkList() {
        head = NULL;
    }

    // Function to create a new node with given data
    node* create_node(char data) {
        node* link_node = new node();
        link_node->data = data;
        return link_node;
    }

    // Function to add a new node to the tail of the linked list
    void add_node_to_tail(char data) {
        if (head == NULL) {
            head = create_node(data);
            head->next = head;
            return;
        }

        node* tail = get_tail();
        node* link_node = create_node(data);
        link_node->next = tail->next;
        tail->next = link_node;
    }

    // Function to get the tail of the linked list
    node* get_tail() {
        node* iter = head;
        while (iter->next != head) {
            iter = iter->next;
        }
        return iter;
    }

    // Function to get the head of the linked list
    node* get_head() {
        return head;
    }

    // Function to print the linked list in a circular manner
    void print(SinglyCircularLinkList Ring, node* head) {
        node* itera = head;
        if (itera == NULL) {
            return;
        } else {
            if (itera->next == Ring.get_head()) {
                cout << itera->data << endl;
                return;
            }
            cout << itera->data;
            print(Ring, head->next);
            cout << itera->data;
        }
    }

    // Function to search for a node with a given key and return the node
    node* search_node(char key) {
        node* iter = head;
        while (iter->data != key) {
            iter = iter->next;
            if (iter == head)
                return NULL;
        }
        return iter;
    }

    // Function to insert a new node with 'info' after the node with key 'key'
    void insert_at_value(char info, char key) {
        if (head == NULL)
            return;

        node* search = search_node(key);
        node* link_node = create_node(info);
        link_node->next = search->next;
        search->next = link_node;
    }

    // Function to get the previous node of a given node
    node* get_prev(node* random_node) {
        node* temp_iter = head;
        if (random_node == NULL)
            return NULL;
        if (random_node == head)
            return head;
        while (temp_iter->next != random_node) {
            temp_iter = temp_iter->next;
        }
        return temp_iter;
    }

    // Function to delete a node with a given key
    void delete_node(char key) {
        node* del_node = search_node(key);
        node* tail = get_tail();
        node* prev = get_prev(del_node);

        if (del_node == head) {
            tail->next = del_node->next;
            if (head->next == head)
                head = NULL;
            else
                head = head->next;

            delete del_node;
            del_node = NULL;
        } else {
            prev->next = del_node->next;
            delete del_node;
            del_node = NULL;
        }
    }

    // Function to count the number of spaces in the linked list
    void count() {
        int counter = 0;
        node* temp1 = head;
        while (temp1->next != head) {
            if (temp1->data == ' ') {
                counter++;
            }
            temp1 = temp1->next;
        }
        counter += 1;
        cout << counter;
    }
};

int main() {
    SinglyCircularLinkList Ring;

    // Adding characters to the linked list
    Ring.add_node_to_tail('h');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('v');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('r');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail('b');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('d');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('h');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('w');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('a');
    Ring.add_node_to_tail('r');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail(' ');
    Ring.add_node_to_tail('y');
    Ring.add_node_to_tail('o');
    Ring.add_node_to_tail('u');

    // Printing the linked list
    Ring.print(Ring, Ring.get_head());

    // Counting the spaces in the linked list
    Ring.count();

    return 0;
}
