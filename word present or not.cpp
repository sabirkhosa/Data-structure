#include<iostream>
using namespace std;

// Node structure for the linked list
struct node{
    char data;
    node *next;
};

// Linked list class
class SinglyCircularLinkList{
private:
    node* head;

public:
    // Constructor to initialize the head as NULL
    SinglyCircularLinkList(){
        head = NULL;
    }

    // Function to create a new node with given data
    node* create_node(char data){
        node* link_node = new node();
        link_node->data = data;
        return link_node;
    }

    // Function to add a node to the tail of the list
    void add_node_to_tail(char data){
        if (head == NULL){
            head = create_node(data);
            head->next = head;
            return;
        }
        node* tail = get_tail();
        node* link_node = create_node(data);
        link_node->next = tail->next;
        tail->next = link_node;
    }

    // Function to get the tail of the list
    node* get_tail(){
        node* iter = head;
        while(iter->next != head){
            iter = iter->next;
        }
        return iter;
    }

    // Function to get the head of the list
    node* get_head(){
        return head;
    }

    // Function to print the list
    void print(){
        node* iter = head;
        if (head == NULL) return;
        do{
            cout << iter->data;
            iter = iter->next;
        } while(iter != head);
        cout << endl;
    }

    // Function to search for a node with a specific key
    node* search_node(char key){
        node* iter = head;
        while(iter->data != key){
            iter = iter->next;
            if (iter == head) return NULL;
        }
        return iter;
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

    // Function to delete a node with a specific key
    void delete_node(char key){
        node* del_node = search_node(key);
        node* tail = get_tail();
        node * prev = get_prev(del_node);
        if (del_node == head){
            tail->next = del_node->next;
            if(head->next == head) head = NULL;
            else head = head->next;

            delete del_node;
            del_node = NULL;
        }
        else {
            prev->next = del_node->next;
            delete del_node;
            del_node = NULL;
        }
    }

    // Function to check if a specific word is present in the list
    void check_word(){
        string st = "";
        string word;
        cout << "Input a word: " << endl;
        cin >> word;
        int flag = 0;
        node* temp1 = head;
        while(temp1->next != head){
            if(temp1->data == ' '){
                if(word == st){
                    cout << "Yes, the word is present." << endl;
                    flag = 1;
                    break;
                } else {
                    st = "";
                }
            }
            if (temp1->data != ' '){
                st += temp1->data;
            }
            temp1 = temp1->next;
        }
        if (!flag){
            cout << "Not Found" << endl;
        }
    }
};

int main(){
    SinglyCircularLinkList Ring;

    Ring.add_node_to_tail('h');
    Ring.add_node_to_tail('e');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('l');
    Ring.add_node_to_tail('o');
    // ... continue adding nodes

    Ring.check_word();

    return 0;
}
