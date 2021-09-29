#include<iostream>
using namespace std;
class stack{
	private:
		int *arr;
		int *top,*n;
		int s;
		public:
		 stack(int s)
			{
			top=NULL;
			n=NULL;
			arr=new int[s];
		 	n=arr;
			
			}
		bool is_empty()
		{
			if (top==NULL)
			{
				return true;
			}
			else
				return false;
		}
		
		bool is_full()
		{
			if(top==n+(s-1))
			{
				return true;
			}
			else
				return false;
			
		}
		
		void push(int val)
		{
			if(is_full())
			{
				cout<<"overflow "<<endl;
			}
			
			else{
				
				if (top==NULL)
				{
					top=arr;
					*top=val;
					return;
				}
			    else
				{
			
					top=top+1;
					*top=val;
					return;
				}
			}
			
		
	}
		
		void pop()
		{
			if(is_empty())
			{
				cout<<"underflow "<<endl;
			}
			else{
		
				if(top==n)
				{
					
					int *a;
					a=top;
					top=NULL;
					cout<<*a<<endl;
			}
				else
			{
					int *temp;
					temp=top;
					top=top-1;
					cout<<*temp<<endl;
				}
				
		}
			
			}
			
		
	
		
		int is_top(){
			return *top;
		}
			
};

int main()
{
	stack obj(7);
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(6);
	obj.push(7);
	//int b=	obj.is_top();
//	cout<<"top is :"<<b<<endl;
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	//obj.pop();
//	obj.pop();
	return 0;
}







