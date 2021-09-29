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
	int hon,_height_;
public:
    BST() {
		root = NULL;
		hon=_height_=0;
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
		if (temp == NULL){
			return;
		}
		else{
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
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
		if(temp->data==val){
			hon=i;
		}
		if(temp->right!=NULL){
			i++;
			height(temp->right,val,i);
			i--;
		}
			
	}
	
	 int count_node(node* temp5)
    {
        if(temp5==NULL)
        {
            return 0;
        }
        else{
            return(count_node(temp5->left) + 1 + count_node(temp5->right));  
     }
    }
	
	int Return_height() {
		return _height_;
		
	}
	
	int return_height_of_node(){
		return hon;
	}
	
};

int main(){
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
    int x=bst.count_node(bst.Get_Root());
    cout<<x;
    bst.print(bst.Get_Root());
   // cout<<endl;
   // bst.height(bst.Get_Root(),1,0);
    //cout<<"height is "<<bst.Return_height();
    //cout<<"height of specific is "<<bst.return_height_of_node();
    
}
