#include<iostream>
using namespace std;

// Node structure for the linked list
struct node{
    int data;
    node* next;
};

// Linked list class
class List{
private:
    node *head;

public:
    // Constructor to initialize the head as NULL
    List(){
        head = NULL;
    }

    // Function to create a new node with given data
    node * get_new_node(int data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    // Function to add a node to the head of the list
    void add_link_node_to_head(int data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    // Function to add a node to the tail of the list
    void add_link_node_to_tail(int data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }

        node* data_node = get_new_node(data);
        node *tail = get_tail(head);
        tail->next = data_node;
    }

    // Function to get the head of the list
    node* get_head(){
        return head;
    }

    // Function to get the tail of the list
    node* get_tail(node* head){
        node* tail_hunter = head;
        while(tail_hunter->next != NULL)
            tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Function to search for a node with a specific key
    node* search_node(int key){
        node* temp = get_head();
        while(temp->data != key){
            temp = temp->next;
            // If we reach the head again, the key is not present
            if(temp == head){
                return NULL;
            }
        }
        return temp;
    }

    // Function to get the data of a node
    int get_data(node* random_node){
        if (random_node == NULL)
            return 0;
        else return random_node->data;
    }

    // Function to get the previous node of a given node
    node* get_prev(node* random_node){
        node* temp_iter = head;
        if (random_node == NULL)
            return NULL;
        if (random_node == head)
            return head;
        while(temp_iter->next != random_node){
            temp_iter = temp_iter->next;
        }
        return temp_iter;
    }        

    // Function to print the list
    void print(){
        node* itera = head;
        while(itera){
            cout << itera->data << " ";
            itera = itera->next;
        }
        cout << endl;
    }

    // Task solution: Function to split and add nodes with multiple digits
    void split_add(){
        node* temp = head;
        int var1, var2, var3 = 0;
        while(temp->next != NULL){
            var1 = get_data(temp);
            // If the data has more than one digit
            if(var1 / 10 > 0){
                var2 = var1;
                node* search = search_node(var1);
                node* prev = get_prev(search);
                // Remove the node with multiple digits from the list
                prev->next = search->next;
                delete search;
                search = NULL;
                
                // Add individual digits as new nodes
                while(var2 / 10 != 0){
                    var3 = var2 % 10;
                    node* temp1 = get_new_node(var3);
                    temp1->next = prev->next;
                    prev->next = temp1;
                    var2 = var2 / 10;
                }
                
                // Add the last digit as a new node
                node* temp2 = get_new_node(var2);
                temp2->next = prev->next;
                prev->next = temp2;
            }
            temp = temp->next;
        }
    }
};

int main(){
    List l1;
    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(101);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(4);
    
    cout << "Original List: ";
    l1.print();

    l1.split_add();

    cout << "Modified List: ";
    l1.print();

    return 0;
}
