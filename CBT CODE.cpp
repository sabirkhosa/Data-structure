#include<iostream>
#include <math.h>
using namespace std;
 
struct node {
    int data;
    node *left, *right;
};
class CBT
{
	private:
 	node* temp;
 	public:
 		node* root;
    CBT()
    {
       
    	root=temp=NULL;
	}
    node* Get_Root() 
    {
		return root;
	}
    void inorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }

       
        inorder(root->left);

        cout<<root->data<<" ";

        inorder(root->right);
        
    }


    node* newNode(int key)
    {
        node* temp1 = new node;
        temp1->data = key;
        temp1->left = temp1->right = NULL;
 
        return temp1;
    }

   int heighs(node* iter)
    {
        if (iter==NULL)
        {
            return 0;
        }
        //int lefts,rights;
        int left_s=heighs(iter->left)+1;
        int right_s=heighs(iter->right)+1;
        if(left_s>right_s)
        {
            return left_s;
        }
        else
        {
            return right_s;
        }
        
    }
	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}


    int count_node(node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
         return(count_node(root->left) + 1 + count_node(root->right));  
         
    }

    void CBT_insertion(node *temp,int data)
{
   
    if (root == NULL)
        {
			root = Create(data);
			return;
		}
        int height = heighs(temp->left); 
		cout<<"height is "<<height<<endl; 
            int expected_node = pow(2, height) - 1; // 
            int left_tree_node_count = count_node(temp->left);
        int right_tree_node_count = count_node(temp->right);
   
    if(left_tree_node_count==right_tree_node_count)
    {
        if (temp->left==NULL)
        {
             temp->left = Create(data);
             return;
        }
        
           else  CBT_insertion(temp->left,data);
        }
    else  if(expected_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
             
                temp->left = Create(data);
              
                return;
            }else 
            {
                
                CBT_insertion(temp->left,data);
            }
        }
    else if(temp->right == NULL)
        {
           
            temp->right = Create(data);
           
            return;
        }
        
            else
            {
                
                CBT_insertion(temp->right,data);
            }
            
        
        
        
}
    
       
    };

    

int main()
{
    CBT cbt;
    cbt.CBT_insertion(cbt.Get_Root(), 10);
    cbt.CBT_insertion(cbt.Get_Root(), 6);
    cbt.CBT_insertion(cbt.Get_Root(), 5);
    cbt.CBT_insertion(cbt.Get_Root(), 29);
   cbt.CBT_insertion(cbt.Get_Root(), 28);
    cbt.CBT_insertion(cbt.Get_Root(), 27);
    cbt.CBT_insertion(cbt.Get_Root(), 26);
    cbt.CBT_insertion(cbt.Get_Root(), 25);
    cbt.inorder(cbt.Get_Root());
    return 0;
}
