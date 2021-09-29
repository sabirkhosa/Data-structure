#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	
};

class singularcirculylinklist{
	private:
		node* head;
	public:
		singularcirculylinklist(){
			head=NULL;
			
		}
		
		node* create_node(int data){
			node* link_node=new node();
			link_node->data=data;
			return link_node;
		}
		
		node* get_tail(){
			node* tail=head;
			while(tail->next!=head){
				tail=tail->next;
			}
			return tail;
		}
		
		void add_node_to_tail(int data){
			if(head==NULL){
				head=create_node(data);
				head->next=head;
				return;
			}
			node* tail=get_tail();
			node* link_node=create_node(data);
			link_node->next=tail->next;
			tail->next=link_node;
		}
		
		void print(){
			if(head==NULL){
				return;
			}
			node* iter=head;
			
			do{
				
				cout<<iter->data;
				iter=iter->next;
				cout<<endl;
			}
			
			while(iter!=head);
		
		}
		
		node* search_node(int key){
			node* link_node=head;
			while(link_node->data!=key){
				link_node=link_node->next;
				if()
			}
			return link_node;
		}
};


int main(){
	singularcirculylinklist ring;
	ring.add_node_to_tail(10);
	ring.add_node_to_tail(11);
	ring.add_node_to_tail(12);
	ring.print();
}
