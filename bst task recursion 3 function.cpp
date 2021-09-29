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
	node *deepest_node;
	int hon,current_level,max_sum,_height_;
public:
    BST() {
		root = NULL;
		hon=_height_=current_level=max_sum=0;
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
	
	node* search_node(node* temp2,int val){
		if(temp2->data==val){
			return temp2;
		}
		
		if(temp2->left!=NULL){
			node *temp=NULL;
			temp=search_node(temp2->left,val);
			if(temp!=NULL){
				return temp;
		}
		
	}
		
		if(temp2->right!=NULL){
			return search_node(temp2->right,val);
		}
		return NULL;
	}
	
	int return_count(node* temp1){
		int c=1;
		if(temp1==NULL){
			return 0;
		}
		if(temp1->left!=NULL){
			c+=return_count(temp1->left);
		}
		if(temp1->right!=NULL){
			c+=return_count(temp1->right);
		}
		return c;
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
		if(temp->data==val){
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
	
	void deepest_left_node(node *temp3,bool is_left,int level){
		if(temp3==NULL){
			return;
		}
		
		if(temp3->left==NULL && temp3->right==NULL&& is_left&& level>current_level){
			current_level=level;
			deepest_node=temp3;
		}
		deepest_left_node(temp3->left,true,level=level+1);
		deepest_left_node(temp3->right,false,level=level+1);

	}
	
	void sum_right_leaf_node(node *temp4,bool is_right,int level,int sum){
		if(temp4==NULL){
			return;
		}
		
		if(temp4->left==NULL && temp4->right==NULL&& is_right){
			sum=temp4->data;
			max_sum=sum+max_sum;
		}
		sum_right_leaf_node(temp4->left,false,level=level+1,sum);
		sum_right_leaf_node(temp4->right,true,level=level+1,sum);

	}
	
	int return_sum(){
		return max_sum;
	}
	
	
	
  
  
    // ***************Part A*******************
    int count_nodes(node *iter, int val, int count=0){
        	node* search=NULL;
			search=search_node(iter,val);
			cout<<"val is "<<search->data<<endl;
        	count=return_count(search);
        	return count;
        }
    

 
 
    // ****************Part-B********************
    int left_most_node(node *root_iter){
    		deepest_left_node(root_iter,false,0);
    		int var1=deepest_node->data;
			height(root_iter,var1,0);
			int var2=return_height_of_node();
			return var2;
    
}

     
    // **********************PART-C********************
    int right_leaves(node* root_iter){
        sum_right_leaf_node(root_iter,false,0,0);
			int var3=return_sum();
			return var3;
    
    }


/*
    // *********************PART-D******************
    int min_diff(node *root_iter,int diff=0){
        // YOUR CODE HERE
        }

*/
};

int main() {
	BST bst;
	bst.Insertion(bst.Get_Root(), 10);
    bst.Insertion(bst.Get_Root(), 4);
    bst.Insertion(bst.Get_Root(), 1);
    bst.Insertion(bst.Get_Root(), 8);
    bst.Insertion(bst.Get_Root(), 9);
  //  bst.Insertion(bst.Get_Root(), 7);
  //  bst.Insertion(bst.Get_Root(), 5);
    bst.Insertion(bst.Get_Root(), 12);
    bst.Insertion(bst.Get_Root(), 14);
    bst.Insertion(bst.Get_Root(), 15);
    bst.print(bst.Get_Root());
    int x=bst.count_nodes(bst.Get_Root(),10,0);
    cout<<"number of nodes are "<<x<<endl;
  //  bst.height(bst.Get_Root(),5,0);
  //  int z=bst.return_height_of_node();
  //  cout<<"height of specific node is "<<z<<endl;
    int a=bst.left_most_node(bst.Get_Root());
    cout<<"height of left most is "<<a<<endl;
    int b=bst.right_leaves(bst.Get_Root());
    cout<<"sum of right leave is "<<b;
    return 0;

}
