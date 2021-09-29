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
		
		void insert (node *temp,int number){


if( root==NULL )
   {
     temp=new node;
     temp->info = number;
     temp->left=NULL;
     temp->right=NULL;
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
	 temp->left=new node;
	 temp->left->info = number;
	 temp->left->left=NULL;
	 temp->left->right=NULL;
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
	 temp->right=new node;
	 temp->right->info = number;
	 temp->right->left=NULL;
	 temp->right->right=NULL;
	 return;
       }
   }
   
}


void print(node *temp){
	if(temp==NULL){
		return;
	}
	cout<<temp->info;
	print(temp->left);
	print(temp->right);
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
	obj.insert(obj.root,18);
	obj.print(obj.root);
	return 0;
}

