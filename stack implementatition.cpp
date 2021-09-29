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
			if(top==NULL){
				 top=arr;
				*top=val;
				top++;
				len++;
				return;
			}
			else{
				*top=val;
				top++;
				len++;
					}
		}
		else{
			cout<<"overflow "<<endl;
		}
}
	int pop(){
		if(!list::is_empty()){
				if(top==n){
					top=arr;
					int *temp1;
					*temp1=*top;
					return *temp1;
				}
		
			else
			{
			//	cout<<"len after first "<<len<<endl;
				int *temp;
				temp=top;
				top=top-1;
				len--;
				//cout<<"len after first "<<len<<endl;
				return *temp;
				delete temp;
				temp=NULL;
			}
			
		}
		else{
			cout<<"underflows "<<endl;
		}
		
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
	list obj(4);
	obj.push(5);
	obj.push(7);
	obj.push(6);
	obj.push(9);
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	return 0;
}
