#include<iostream>
using namespace std;

class queue{
	private:
		int size;
		int *arr;
		int *front;
		int *rear;
		int len;
	public:
		queue(int s){
			size=s;
			arr=new int [size];
			len=0;
			front=rear=NULL;
			rear=arr;
			front=arr;
		}
		bool is_empty(){
			if(len==0)
				return true;
			else
				return false;
				
		}
		
		bool is_full(){
			if(len==size)
				return true;
			else
				return false;
		}
		
		void enqueue(int val){
			if(is_full()){
				cout<<"overflow"<<endl;
				return;
			}
			if(is_empty()){
				*rear=val;
				len++;
			}
			else{
				rear++;
				*rear=val;
				len++;
			}
		}
		
		int dequeue(){
			if(is_empty()){
				cout<<"underflow"<<endl;
				return 10;
			}
			
			else{
				front++;
				len--;
				return *front;
			}
			front=arr;
			}
		
	
		int peek(){
			if(is_empty()){
				cout<<"underflow"<<endl;
			}
			else
				return *front;	
		
	}
	
			
};

int main(){
	queue obj(4);
	obj.enqueue(5);
	obj.enqueue(6);
	obj.enqueue(7);
	obj.enqueue(8);
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	cout<<obj.dequeue();
	//cout<<obj.dequeue();
//	cout<<obj.peek();
	return 0;

}
