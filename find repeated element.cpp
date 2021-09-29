#include<iostream>
#include<cmath>
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
        if(tail_hunter->next==NULL){
        	return tail_hunter;
    }
    	get_tail(head->next);
    }
    /*
    
    int get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
    }
    
    bool search_node(int key){
    	node* temp= get_head();
    	while(temp->data!=key){
    		temp=temp->next;
    		if((temp==head)||(temp==NULL)){
    			return false;
			}
		}
		return true;
	}
    
    void find_rep(List l1,List &l2){
    	int count=0;
		int rep=0;
		int val=0;
	//	int val1=0;
    	node* temp=l1.get_head();
    	while(temp!=NULL){
    		val=0;
    		count=0;
    		val=temp->data;
    		cout<<"here"<<endl;
    		cout<<val;
    		node *temp1=l1.get_head();
    		while(temp1!=NULL){
    			//cout<<val;
    			bool temp2=l2.search_node(val);
    			//cout<<temp2->data;
    			if(temp2){
    				temp1=temp1->next;
    				continue;
				}
    			
    			if(temp1->data==val){
    				count++;
				}
				cout<<"kerjpfo"<<temp->next<<endl;
				temp1=temp1->next;
				
			}
			cout<<count;
			if(count>1){
				rep+=1;
				l2.add_link_node_to_tail(val);
			}
			temp=temp->next;
		cout<<"repeated numbers are :"<<rep;
	}
}
    
    
    */
    int calculate_len(node* head,int sum){
    	node *itera1=head;
    	if(itera1->next==NULL){
    		cout<<endl;
    		return sum;
			}
		else{
		calculate_len((head->next),sum+1);
	}
}
     void print(node *head){
        node* itera =head;
        if(itera->next==NULL){
        	cout<<endl;
            return;
        }
        cout<<itera->data;
        print(head->next);
        cout<<itera->data;
    }
};
        
        
        
int main(){
	List l1,l2;
	int sum=0;
    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(1);
    l1.add_link_node_to_tail(4);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(2);
    l1.add_link_node_to_tail(3);
    l1.add_link_node_to_tail(5);
    l1.add_link_node_to_tail(3);
    l1.print(l1.get_head());
    cout<<l1.calculate_len(l1.get_head(),sum);
    //l1.find_rep(l1,l2);
   // l2.print();
    
}
