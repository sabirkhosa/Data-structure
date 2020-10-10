#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class List{
    private:
        node *head;
    public:
        List(){
            head = NULL;
        }
    
    node * get_new_node(int data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    void add_link_node_to_head(int data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    void add_link_node_to_tail(int data){
        if(head==NULL){
            head = get_new_node(data);
           
            return;
        }
       
        node* data_node = get_new_node(data);
        node *tail = get_tail(head);
        tail->next = data_node;
       
    }

    node* get_head(){
        return head;
    }

    node* get_tail(node* head){
        node* tail_hunter =head;
        while(tail_hunter->next!=NULL)
        tail_hunter = tail_hunter->next;
        return tail_hunter;
    }
    
    node* search_node(int key){
    	node* temp= get_head();
    	while(temp->data!=key){
    		temp=temp->next;
    		if(temp==head){
    			return NULL;
			}
		}
		return temp;
	}

    // Task solution

    int get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
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

    void print(){
        node* itera = head;
        while(itera){
            cout<<itera->data<<" ";
            itera = itera->next;
        }
    }
    void split_add(){
    	node* temp=head;
    	int var1,var2,var3=0;
    	while(temp->next!=NULL){
    		var1=get_data(temp);
    		if(var1/10>0){
    			var2=var1;
    			node* search=search_node(var1);
    			node* prev=get_prev(search);
    			prev->next=search->next;
    			delete search;
    			search=NULL;
    			while(var2/10!=0){
    				var3=var2%10;
    				node* temp1=get_new_node(var3);
    				temp1->next=prev->next;
    				prev->next=temp1;
    				var2=var2/10;
    		
    				
				}
				
			node* temp2=get_new_node(var2);
			temp2->next=prev->next;
			prev->next=temp2;
			}
			temp=temp->next;
    	
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
   // l1.print();
    l1.split_add();
    l1.print();
    return 0;
}
