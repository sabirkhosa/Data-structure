#include<iostream>
using namespace std;
 
struct node{
	int info;
	node *left;
	node *right;
};

class CBT{
	private:
		node* temp;
	public:
		node* root;
		int _height_;
		CBT(){
			root=temp=NULL;
			_height_=0;
		}
		
    node* Get_Root() 
    {
		return root;
	}
   void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->info<< " ";
		print(temp->right);
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

  int height(node* iter)
    {
        if (iter==NULL)
        {
            return 0;
        }
        int left=height(iter->left);
        int right=height(iter->right);
        if(left>right)
        {
            return left+1;
        }
        else
        {
            return right+1;
        }
        
    }
	
	 int count_node(node* node)
    {
    	int c=1;
        if(node==NULL)
        {
            return 0;
        }
        else{
        	c+=count_node(node->left);
			c+=count_node(node->right);  
     }
     	return c;
    }

	

    void CBT_insertion(node *temp,int data)
{
   
    if (root == NULL)
        {
			root =create_new_node(data);
			temp=root;
			return;
		}
	//	cout<<"here ";
		int h1=height(temp->left);
		cout<<"height is :"<<h1<<endl;
        int expected_node = (power(2, h1) - 1);
       // cout<<"here 4";
       // t=temp->left->info;
        int left_tree_node_count = count_node(temp->left);
        int right_tree_node_count = count_node(temp->right);
   		
    if(left_tree_node_count==right_tree_node_count)
    {
        if (temp->left==NULL)
        {
             temp->left = create_new_node(data);
             return;
        }
        
           else  CBT_insertion(temp->left,data);
        }
    else  if(expected_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
             
                temp->left =create_new_node(data);
              
                return;
            }else 
            {
                
                CBT_insertion(temp->left,data);
            }
        }
        else if(temp->right == NULL)
        {
           
            temp->right = create_new_node(data);
           
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
    cbt.print(cbt.Get_Root());
    return 0;
}
