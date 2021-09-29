#include<iostream>
using namespace std;
struct node
{
  int info;
  node *left,*right;
};

class bst
{
   private :
	    node *temp;
   public  :
	    node *root;
	    int number;
	     bst(){
	    	root=temp=NULL;
		}
		node* createnewnode(int data){
			node* newnode=new node();
			newnode->info=data;
			newnode->left=newnode->right=NULL;
			return newnode;
		}
		
	void insert (node *temp,int number){

				if( root==NULL )
				   {
				     temp=createnewnode(number);
				     root=temp;
				     return;
				   }
				
				  if( temp->info==number )
				   {
				      cout<<temp->info<<" is already present in tree."<<endl;
				      return;
				    }
				    
				    if(temp->info > number)
				   {
				      if( temp->left!=NULL )
				       {
						 insert(temp->left,number);
						 return;
				       }
				      else
				       {
					 temp->left=createnewnode(number);
					 return;
				       }
				   }
				   
				   if(temp->info < number)
				   {
				      if( temp->right!=NULL )
				       {
						 insert( temp->right,number );
						 return;
				       }
				      else
				       {
					 temp->right=createnewnode(number);
					 return;
				       }
				   }
				   
				}
				/*
				
				
void  Delete(node *temp, int data) {
		if(root == NULL){
			return root; 
		}
		else{
			if(data < temp->info){
				if (temp->left!=NULL){
					Delete(temp->left,data);
				}
			}
			
				
		}
		else
			if (data > root->data){
				if (temp->right!=NULL){
					Delete(root->right,data);
				}
		}
	}
	*/
					

int  count_node(node *temp){
	int count=1;
	if(temp==NULL){
		return 0;
	}
	else{
			count+=count_node(temp->left);
			count+=count_node(temp->right);
		}
	return count;
	
}
 
int maxi (int left , int right){
	if (left > right){
		return left;
	}else{
		return right;
	}
} 

int print2(node *left){
	int count =1;
	if (left->left!= NULL){
		count += print2(left->left);
		return count;
	}
}

int print3(node *right){
	int count =1;
	if (right->right!= NULL){
		count += print2(right->right);
		return count;
	}
}


int  print1(node *temp){
	int left=1;
	int right=1;

	if(temp->left!=NULL){
		left+=print2(temp->left);
		//return count;
	}
	if(temp->right!=NULL){
		right+=print3(temp->right);
		}
	return maxi(right,left);
	//	return 0;
	//return count;
	
}
   
};

int main(){
	bst obj;
	obj.insert(obj.root,10);
	obj.insert(obj.root,12);
	obj.insert(obj.root,11);
	obj.insert(obj.root,9);
	obj.insert(obj.root,10);
	obj.insert(obj.root,4);
	obj.insert(obj.root,5);
	obj.insert(obj.root,15);
	obj.insert(obj.root,14);
	obj.insert(obj.root,18);
	int x=count_node(obj.root);
	cout<<x<<endl;
	int y = obj.print1(obj.root);
	cout<<"Height : "<<y;
	return 0;
}

