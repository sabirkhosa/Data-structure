#include<iostream>
using namespace std;
class node{
	public:
		node* next;
		int info;
		node(int val){
			info=val;
			next=NULL;
		}
};

class list1{
	public:
		node *head1,*curr1,*temp1;
		list1(){
			head1=curr1=temp1=NULL;
			
		}
		void create_list1(int val){
			if(head1==NULL){
				head1=new node(val);
				head1->info=val;
				head1->next=NULL;
				curr1=head1;
					return;
						}
			
				temp1=new node(val);
				temp1->next=curr1->next;
				curr1->next=temp1;
				curr1=temp1;
			
		}
		
		int count1(int count1){
		temp1=head1;
		while(temp1!=NULL){
		
			temp1=temp1->next;
			count1++;
		}
		return count1;
			
		}
		
		void print(){
			temp1=head1;
			while(temp1!=NULL){
				cout<<temp1->info;
				temp1=temp1->next;
			
			}
	}
			
		};
	
	class list2{
		public:
			node *temp2,*curr2,*head2;
			list2(){
				head2=curr2=temp2=NULL;
			}
			
			void create_list2(int val){
				if(head2==NULL){
					head2=new node(val);
					head2->info=val;
					head2->next=NULL;
					curr2=head2;
						return;
							}
				
					temp2=new node(val);
					temp2->next=curr2->next;
					curr2->next=temp2;
					curr2=temp2;
				
			}
			
			int count2(int count2){
				temp2=head2;
				while(temp2!=NULL){
				
					temp2=temp2->next;
					count2++;
				}
				return count2;
					
				}
			
				void print1(){
				temp2=head2;
				while(temp2!=NULL){
					cout<<temp2->info;
					temp2=temp2->next;
				}
			}
			
};

class list3{
	public:
		node *head,*curr,*temp,*last1,*last2,*p1,*p2;
		int var1,var2,var3;
			list3(){
				var1=var2=var3=0;
				head=curr=temp=last=p1=p2=NULL;
				
			}
			void create_node(int val){
			if (head==NULL){
				head=new node(val);
				head->info=val;
				head->next=NULL;
				curr=head;
				return;
			}
			temp=new node(val);
			temp->next=curr->next;
			curr->next=temp;
			curr=curr->next;
			
	}
		
	
		void add(node* head1,node* head2,int len){
			last1=head1;
			last2=head2;
			while(last1!=NULL){
				last1=last1->next;
			}
			p1=last1;
			while(last2!=NULL){
				last2=last2->next;
			}
			p2=last2;
			
			for(int i=0; i<len;i++){
				curr=head1;
				temp=head2;
				while(curr->next!=p1){
					curr=curr->next;
				}
				var1=p1->info;
				p1=curr;
					while(temp->next!=p2){
					temp=temp->next;
				}
				var2=p2->info;
				p2=temp;
				var3=var1+var2;
				create_node(var3);
			
			}
	}
	
};


int main(){
	list1 obj;
	list2 obj1;
	int count1=0;
	int count2=0;
	int a,b=0;
	int len=0;
	obj.create_list1(3);
	obj.create_list1(4);
	obj.create_list1(5);
	a=obj.count1(count1);
	obj.print();
	cout<<endl;
	cout<<"2nd link list is "<<endl;
	obj1.create_list2(7);
	obj1.create_list2(8);
	obj1.create_list2(10);
	b=obj1.count2( count2);
	obj1.print1();
	cout<<a<<" "<<b;
	
	if(a>=b){
		len=a;
	}
	else{
		len=b;
	}
	obj.add(head1,head2,len);
	return 0;
}
