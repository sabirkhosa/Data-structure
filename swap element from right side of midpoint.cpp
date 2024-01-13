#include<iostream>
#include<cmath>
using namespace std;

struct node {
    int data;
    node* next;
};

class List {
private:
    node* head;

public:
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

    // Function to add a node to the tail of the list
    void add_link_node_to_tail(int data) {
        if (head == NULL) {
            head = get_new_node(data);
            return;
        }

        node* data_node = get_new_node(data);
        node* tail = get_tail(head);
        tail->next = data_node;
    }

    // Function to get the head of the list
    node* get_head() {
        return head;
    }

    // Function to get the tail of the list
    node* get_tail(node* head) {
        node* tail_hunter = head;
        while (tail_hunter->next != NULL)
            tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Function to get the data of a node
    int get_data(node* random_node) {
        if (random_node == NULL)
            return 0;
        else
            return random_node->data;
    }

    // Function to swap the second half with the first half of the list
    void swap(List l1, List& l2) {
        int val;
        node* temp = l1.get_head();
        double tl, mid;

        // Calculate the length of the list
        while (temp != NULL) {
            tl++;
            temp = temp->next;
        }

        // Find the midpoint of the list
        mid = ceil(tl / 2);

        // Reset temp to the head of the list
        temp = l1.get_head();

        // Move temp to the node at the midpoint
        while (temp->data != mid) {
            temp = temp->next;
        }

        // Create a new list starting from the node after the midpoint
        node* temp1 = temp->next;
        while (temp1 != NULL) {
            val = l1.get_data(temp1);
            l2.add_link_node_to_tail(val);
            val = 0;
            temp1 = temp1->next;
        }

        // Add the node at the midpoint to the new list
        val = l1.get_data(temp);
        l2.add_link_node_to_tail(val);
        val = 0;

        // Reset temp1 to the head of the list
        temp1 = l1.get_head();

        // Add nodes from the head to the node before the midpoint to the new list
        while (temp1 != temp) {
            val = l1.get_data(temp1);
            l2.add_link_node_to_tail(val);
            val = 0;
            temp1 = temp1->next;
        }
    }

    // Function to print the list
    void print() {
        node* itera = head;
        while (itera) {
            cout << itera->data << " ";
            itera = itera->next;
        }
        cout << endl;
    }
};

int main() {
    List l1, l2;

    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(4);
    l1.add_link_node_to_tail(5);
    l1.add_link_node_to_tail(6);
    l1.add_link_node_to_tail(7);
    l1.add_link_node_to_tail(8);
    l1.add_link_node_to_tail(9);

    cout << "Original List: ";
    l1.print();

    l1.swap(l1, l2);

    cout << "Modified List: ";
    l2.print();

    return 0;
}
