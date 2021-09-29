#include<iostream>
using namespace std;

class list{
	private:
		int *top;
		int len,size;
		int *arr,*n;
	public:
		list(int s){
			size=s;
			top,n=NULL;
			arr=new int[size];
			top=arr;
			n=arr;
			len=0;
			}
	
	bool is_empty(){
		if(top==NULL){
			return true;
		}
		return false;
	}
	
	bool is_full(){
		if(len==(size)){
			return true;
		}
		return false;
	}
	
	
	void push(int val){
		if(!list::is_full()){
			if(top==n){
		
				*top=val;
				cout<<"value of top first value "<<*top<<endl;
				top++;
				len++;
				return;
			}
			else{
				*top=val;
				top++;
				len++;
				//return;
					}
		}
		else{
			cout<<"overflow "<<endl;
		}
}
	int pop(){
		if(list::is_empty()){
			cout<<"underflows "<<endl;
			return 0;
		}
		int *a;
		*a=*top;
		top=NULL;
		top--;
		len--;
		return *a;
		
	}
	/*
	int peek(){
		if(!is_empty()){
			cout<<"underflows "<<endl;
			
		}
		else{
			return *top;
		}
	}
	
	*/
};

int main(){
	list obj(3);
	obj.push(5);
	obj.push(7);
	obj.push(6);
	cout<<obj.pop();
	cout<<obj.pop();
	cout<<obj.pop();
	cout<<obj.pop();
//	cout<<obj.peek();
	return 0;
}
