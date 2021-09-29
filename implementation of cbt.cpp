#include <iostream>
using namespace std;

struct node{
	int info;
	node *left;
	node *right;
};

class cbt{
	private:
		node* root;
	public:
		node* temp;
		node* r;
		int count1,hon,_height_,h1;
		cbt(){
			root=temp=r=NULL;
			count1=h1=hon=_height_=0;
		}
		
		node* create_new_node(int data){
			node* tmp=new node();
			tmp->info=data;
			tmp->left=tmp->right=NULL;
			return tmp;
		}
		
		int power(int x,int exp){
			if(exp==0){
				return 1;
			}
			else{
				return x* power(x,exp-1);
			}
		}
		void height(node *temp,int val,int i){
		
		if(temp==NULL)
			return;
		if(temp->left!=NULL){
			i++;
			height(temp->left,val,i);
			i--;
		}
		if(_height_<i){
			_height_ = i;
		}
		if(temp->info==val){
			hon=i;
		}
		if(temp->right!=NULL){
			i++;
			height(temp->right,val,i);
			i--;
		}
			
	}
	
	int Return_height() {
		return _height_;
		
	}
	
	int return_height_of_node(){
		return hon;
	}
	
	node *search(node *temp,int val){
		if(temp->info==val){
			return temp;
		}
		if(temp->left!=NULL){
			node *temp1;
			temp1=NULL;
			temp1=search(temp->left,val);
			if(temp1!=NULL){
				return temp1;
				}
			}
		
		if(temp->right!=NULL){
			return search(temp->right,val);
		}
		return NULL;
	}
	
	int counter(node* temp2){
	int c=1;
	if(temp2->left!=NULL){
		c+=counter(temp2->left);
	}
	if(temp2->right!=NULL){
		c+=counter(temp2->right);
	}
	return c;
	
}
	
	int count_nodes(node* iter, int val, int count=0){
    	node *temp1=search(iter,val);
    	//cout<<"temp1 val is "<<temp1->data<<endl;
    	count=counter(temp1);
    	cout<<"count is "<<count<<endl;
        return count;
    }
		
		void Insertion(node* temp,int data){
			int ah=0;
			int lh=0;
			int d=0;
			int t=0;
			int count=0;
			if(root==NULL){
				root=create_new_node(data);
				temp=root;
				return;
			}
			else{
			
				if(temp->left!=NULL){
					Insertion(temp->left,data);
					}
				else{
					if(temp->right!=NULL){
						Insertion(temp->right,data);
						}
			//	return;
				}
			}	
			
			r=Get_Root();
			d=r->info;
			count=count_nodes(r,d,0);
			 t=temp->info;
			 height(r,d,0);
			 ah=Return_height();
			 //cout<<"val of ah is "<<ah<<endl;
			 height(r,t,0);
			 lh=return_height_of_node();
			int p=power(2,ah+1);
			if(count==(p-1)){

				while(temp->left!=NULL){
					temp=temp->left;
				}
				temp->left=create_new_node(data);
				return;
			}

			if((temp->left!=NULL)&& (temp->right==NULL)){
				temp->right=create_new_node(data);
				return;
				}
				
				cout<<"val of lh is "<<lh<<endl;
				cout<<"val of ah is "<<ah<<endl;
			if((temp->left==NULL)&&(temp->right==NULL)&&(lh<ah)){
				cout<<"ye wali  ";
				temp->left=create_new_node(data);
				return;
				}
				
			
				
			}
			
		
				
			
			
	node *Get_Root() {
		return root;
	}
	
	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->info<< " ";
		print(temp->right);
	}

};


int main(){
	cbt obj;
    obj.Insertion(obj.Get_Root(),10);
    obj.Insertion(obj.Get_Root(),4);
    obj.Insertion(obj.Get_Root(),1);
    obj.Insertion(obj.Get_Root(),8);
    obj.Insertion(obj.Get_Root(),9);
    obj.Insertion(obj.Get_Root(),12);
	obj.Insertion(obj.Get_Root(),24);
    obj.Insertion(obj.Get_Root(),13);
    obj.print(obj.Get_Root());
    return 0;
}
