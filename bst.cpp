#include<iostream>
using namespace std;
class bstnode{
	public:
		int data;
		bstnode* left;
		bstnode* right;
		bstnode(){
			left=NULL;
			right=NULL;
		}
		
		bstnode* createnewnode(int data){
			bstnode* newnode=new bstnode();
			newnode->data=data;
			newnode->left=newnode->right=NULL;
			return newnode;
		}
		// insertion function
		bstnode* insert(bstnode* root,int data){
			if(root==NULL){
				root=createnewnode(data);
			}
			else
				if(data<=root->data){
					root->left=insert(root->left,data);
				}
				else
					if(data>=root->data){
						root->right=insert(root->right,data);
					}
					return root;
		}
		
			//deletion function
		bstnode* Delete(bstnode *root, int data) {
	if(root == NULL){
		return root; 
	}
	else
		if(data < root->data){
		root->left = Delete(root->left,data);
	}
	else
		if (data > root->data){
		root->right = Delete(root->right,data);
	}
	else {
		// case 1
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//  case 2
		else if(root->left == NULL) {
			bstnode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			bstnode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3
		else { 
			bstnode *temp = min(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

};

int main(){

bstnode* root=NULL;
	bstnode obj;
	root=obj.insert(root,12);
	root=obj.insert(root,15);
	root=obj.insert(root,13);
	root=obj.insert(root,14);
	root=obj.insert(root,11);
	root=obj.insert(root,9);
	root=obj.insert(root,10);
	root=obj.insert(root,8);
	obj.Delete(root,15);
	return 0;
}
