#include<iostream>
using namespace std;

struct node{
    char data;
    node *next;
};

class SinglyCircularLinkList{
    private:
        node* head;
    public:
        SinglyCircularLinkList(){
            head = NULL;
        }

        node* create_node(char data){
            node* link_node = new node();
            link_node->data = data;
            return link_node;
        }

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

        node* get_tail(){
            node* iter = head;
            while(iter->next != head){
                iter = iter->next;
            }
            return iter;
        }
        
        node *get_head(){
        	return head;
		}
/*
        void print(){
            node* iter = head;
            if (head == NULL) return;
            do{
                cout<<iter->data;
                iter = iter->next;
            }
            while(iter != head);
            cout<<endl;

        }
*/

		void print(SinglyCircularLinkList Ring,node* head){
			node* itera=head;
			if(itera==NULL){
				return;
			}
			else{
				//cout<<itera->data;
				if(itera->next==Ring.get_head()){
					cout<<itera->data<<endl;
					return;
				
				}
				cout<<itera->data;
				print(Ring,head->next);
				cout<<itera->data;
			}
		//	cout<<itera->data;
		}
		
		
		
		
        node* search_node(char key){
            node* iter = head;
            while(iter->data !=key){
                iter = iter->next;
                if (iter == head) return NULL;
             }
             return iter;
        }

        void insert_at_value(char info, char key){
            if (head == NULL) return;
            node* search = search_node(key);
            node* link_node = create_node(info);
            link_node->next = search->next;
            search->next = link_node;

        }

        node* get_prev(node* random_node){
            node* temp_iter = head;
            if (random_node==NULL)
                    return NULL;
            if (random_node==head)return head;
            while(temp_iter->next!=random_node){
                temp_iter=temp_iter->next;
            }
            return temp_iter;
        }
        
        void  delete_node(char key){
            node* del_node = search_node(key);
            node* tail = get_tail();
            node * prev = get_prev(del_node);
            if (del_node == head){
                tail->next = del_node->next;
                if(head->next==head)head=NULL;
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

        void count(){
        	int counter=0;
        	node *temp1=head;
        	while(temp1->next!=head){
        		if(temp1->data==' '){
        			counter++;
				}
				temp1=temp1->next;
			}
			counter+=1;
			cout<<counter;
		}

};
int main(){

    SinglyCircularLinkList Ring;

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
    Ring.print(Ring,Ring.get_head());
    Ring.count();
    return 0;

}

