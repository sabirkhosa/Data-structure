#include<iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class BST {

private:
	node *root;
	int max,val1,gh;
public:
    BST() {
		root = NULL;
		max=val1=gh=0;
	}

	bool check_left(node *temp) {
		if (temp->left == NULL) {
			return true;
		}
		else return false;
	}

	bool check_right(node *temp) {
		if (temp->right == NULL)
			return true;
		else return false;
	}

	bool is_greater(int val, int val_1) {
		if (val > val_1)
			return true;
		else return false;
	}

	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		if (root == NULL) {
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data)) {
			if (check_left(temp)) {
				temp->left = Create(data);
				return;
			}
			else Insertion(temp->left, data);

		}
		else {
			if (check_right(temp)) {
				
				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else Insertion(temp->right, data);
		}

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}
	
	node *search(node *temp,int val){
		if(temp->data==val){
			cout<<endl;
			//cout<<"tmp val is "<<temp->data; 
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
	/*
	int height(node* temp1,int h){
		if(temp1->left!=NULL){
			height(temp1->left,lh=lh+1);
		}
		if(temp1->right!=NULL){
			height(temp1->right,rh=rh+1);
		}
		if(lh>=rh){
			return lh+1;
		}
	}
	
	
	
int height(node *temp1)
{
   if(temp1 == NULL){
   		return 0;
}
else{
   int left = height(temp1->left);
   int right = height(temp1->right);
  // cout<<"left is "<<left<<endl;
  // cout<<"ri8 is "<<right<<endl;
   if(left > right){
       return 1 + left;
   }
   else{
   		return 1 + right;
   }
 } 
}

	//int Return_height(){
	//	return _height_;
	


int  counter(node *temp){
	int count=1;
	if(temp==NULL){
		return 0;
	}
	else{
		count+=counter(temp->left);
		count+=counter(temp->right);
		return count;
	
}
}
*/

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


  
    // ***************Part A*******************
    int count_nodes(node* iter, int val, int count=0){
    	node *temp1=search(iter,val);
    	cout<<"temp1 val is "<<temp1->data<<endl;
    	count=counter(temp1);
        return count;
    }
    /*
    int return_height(node* temp,int val,int lh){
    	if(temp->data==val){
    		cout<<"value of lh is "<<lh<<endl;;
    		return lh+1;
		}
		if(temp->left!=NULL){
			return_height(temp->left,val,lh=lh+1);
		}
		if(temp->right!=NULL){
			return_height(temp->right,val,lh=lh+1);
		}
	}
	*/
/*
 
    // ****************Part-B********************
    int left_most_node(node *root_iter){
        	if((root_iter->left->left==NULL)&&(root_iter->left->right==NULL)){
        		node* temp1=Get_Root();
        		int val=root_iter->data;
        		cout<<"val is "<<val<<endl;
        		int h1=return_height(temp1,val,0);
        		cout<<"value of h is "<<h1;
        		if(max<h1){
        			max=h1;
				}
        		
			}
			if(root_iter->left!=NULL){
				 left_most_node(root_iter->left);
			}
			
			if(root_iter->right!=NULL){
				 left_most_node(root_iter->right);
			
			}
			return max;
		}

  
    // **********************PART-C********************
    int right_leaves(node* root_iter){
    	if((root_iter->left->left==NULL)&&(root_iter->left->right==NULL)){
        		val1=root_iter->right->data;
        		
        	}
        if(root_iter->left!=NULL){
				left_most_node(root_iter->left);
			}
			
		if(root_iter->right!=NULL){
				left_most_node(root_iter->right);
			
			}
    }

	int return_min(int a,int b){
		if(a>b){
			return a;
		}
		else{
			return b;
		}
	}
	
	int difference(node *temp,int diff){
		if(temp==NULL){
			return diff;
		}
		if(temp->left!=NULL){
			int left=(temp->data-temp->left->data);
			diff=return_min(diff,left);
		}
		if(temp->right!=NULL){
			int right=(temp->data-temp->right->data);
			diff=return_min(diff,right);
		}
	}

    // *********************PART-D******************
    int min_diff(node *root_iter,int diff=0){
        	int p=difference(root_iter->left,0);
        	int q=difference(root_iter->right,0);
        	return min(p,q);
        }
*/

};

int main() {
	BST bst;
	bst.Insertion(bst.Get_Root(),10);
    bst.Insertion(bst.Get_Root(),4);
    bst.Insertion(bst.Get_Root(),8);
    bst.Insertion(bst.Get_Root(),9);
    bst.Insertion(bst.Get_Root(),1);
    bst.Insertion(bst.Get_Root(),12);
	bst.Insertion(bst.Get_Root(),24);
    bst.Insertion(bst.Get_Root(),13);
    /*
   // bst.Insertion(bst.Get_Root(),24);
    bst.Insertion(bst.Get_Root(),5);
    bst.Insertion(bst.Get_Root(),8);
    bst.Insertion(bst.Get_Root(),4);
   // bst.Insertion(bst.Get_Root(),5);
   */
    bst.print(bst.Get_Root());
   int x=bst.count_nodes(bst.Get_Root(),8,0);
   cout<<"number of nodes are "<<x<<endl;
   // int y=bst.left_most_node(bst.Get_Root());
   // cout<<"left most h is "<<y;
  //  int z=bst.min_diff(bst.Get_Root(),0);
  //  cout<<"min difference is "<<z;
    //bst.height(bst.Get_Root(),0);
    //cout<<bst.Return_height();
    
    

}
