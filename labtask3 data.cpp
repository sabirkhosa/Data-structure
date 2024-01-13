#include<iostream>
using namespace std;

class node {
public:
    node* next;
    int info;

    // Constructor to initialize node with given value
    node(int val) {
        info = val;
        next = NULL;
    }
};

class list1 {
public:
    node* head1, * curr1, * temp1;

    // Constructor to initialize list1
    list1() {
        head1 = curr1 = temp1 = NULL;
    }

    // Function to create nodes in list1
    void create_list1(int val) {
        if (head1 == NULL) {
            head1 = new node(val);
            head1->info = val;
            head1->next = NULL;
            curr1 = head1;
            return;
        }

        temp1 = new node(val);
        temp1->next = curr1->next;
        curr1->next = temp1;
        curr1 = temp1;
    }

    // Function to count nodes in list1
    int count1(int count1) {
        temp1 = head1;
        while (temp1 != NULL) {
            temp1 = temp1->next;
            count1++;
        }
        return count1;
    }

    // Function to print nodes in list1
    void print() {
        temp1 = head1;
        while (temp1 != NULL) {
            cout << temp1->info << " ";
            temp1 = temp1->next;
        }
    }
};

class list2 {
public:
    node* temp2, * curr2, * head2;

    // Constructor to initialize list2
    list2() {
        head2 = curr2 = temp2 = NULL;
    }

    // Function to create nodes in list2
    void create_list2(int val) {
        if (head2 == NULL) {
            head2 = new node(val);
            head2->info = val;
            head2->next = NULL;
            curr2 = head2;
            return;
        }

        temp2 = new node(val);
        temp2->next = curr2->next;
        curr2->next = temp2;
        curr2 = temp2;
    }

    // Function to count nodes in list2
    int count2(int count2) {
        temp2 = head2;
        while (temp2 != NULL) {
            temp2 = temp2->next;
            count2++;
        }
        return count2;
    }

    // Function to print nodes in list2
    void print1() {
        temp2 = head2;
        while (temp2 != NULL) {
            cout << temp2->info << " ";
            temp2 = temp2->next;
        }
    }
};

class list3 {
public:
    node* head, * curr, * temp, * last1, * last2, * p1, * p2;
    int var1, var2, var3;

    // Constructor to initialize list3
    list3() {
        var1 = var2 = var3 = 0;
        head = curr = temp = last1 = p1 = p2 = NULL;
    }

    // Function to create a new node with given value
    void create_node(int val) {
        if (head == NULL) {
            head = new node(val);
            head->info = val;
            head->next = NULL;
            curr = head;
            return;
        }

        temp = new node(val);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next;
    }

    // Function to add nodes from list1 and list2
    void add(node* head1, node* head2, int len) {
        last1 = head1;
        last2 = head2;

        // Move to the end of list1
        while (last1 != NULL) {
            last1 = last1->next;
        }
        p1 = last1;

        // Move to the end of list2
        while (last2 != NULL) {
            last2 = last2->next;
        }
        p2 = last2;

        // Add corresponding nodes from list1 and list2
        for (int i = 0; i < len; i++) {
            curr = head1;
            temp = head2;

            // Move to the node before the end of list1
            while (curr->next != p1) {
                curr = curr->next;
            }
            var1 = p1->info;
            p1 = curr;

            // Move to the node before the end of list2
            while (temp->next != p2) {
                temp = temp->next;
            }
            var2 = p2->info;
            p2 = temp;

            // Calculate the sum and create a new node in list3
            var3 = var1 + var2;
            create_node(var3);
        }
    }
};

int main() {
    list1 obj;
    list2 obj1;
    int count1 = 0;
    int count2 = 0;
    int a, b = 0;
    int len = 0;

    // Create nodes in list1
    obj.create_list1(3);
    obj.create_list1(4);
    obj.create_list1(5);

    // Count and print nodes in list1
    a = obj.count1(count1);
    obj.print();
    cout << endl;

    // Create nodes in list2
    cout << "2nd link list is" << endl;
    obj1.create_list2(7);
    obj1.create_list2(8);
    obj1.create_list2(10);

    // Count and print nodes in list2
    b = obj1.count2(count2);
    obj1.print1();
    cout << endl;

    // Determine the maximum length between list1 and list2
    if (a >= b) {
        len = a;
    }
    else {
        len = b;
    }

    // Add nodes from list1 and list2 and print the result
    obj.add(obj.head1, obj1.head2, len);

    return 0;
}
