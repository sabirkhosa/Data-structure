#include<iostream>
#include<string>
using namespace std;

class list{
	private:
		int *arr;
	public:	
		int size,len,*temp,*temp1,*current;
		list(){
			cout<<"enter size :";
			cin>>size;
			len=0;
			current=NULL;
			temp=NULL;
			temp1=NULL;
			arr=new int[size];
			current=arr;
			for (int i=0;i<size;i++){
				arr[i]=0;
				current++;
			}
			current=0;
		}
		
		void insert(int value){
			if (len==size)
			{
			cout<<"arrY IS FILLED:";
				return;
			}
		//	if(len==0){
		//		*arr=value;
		//		current=arr;
		//		len++;
		//		return;
		//	}
			else{
				current=arr;
				current=current+len;
				*current=value;
				len++;
			}
			
			}
			
		void add(int pos,int val){
			current=arr;
			temp=current;
			for(int i=1;i<size;i++){
				temp++;
			}
			temp1=temp-1;
			for(int i=1;i<pos;i++){
				current++;
			}
			while(temp!=current){
				int a=0;
				a=*temp1;
				*temp1=*temp;
				*temp=a;
				 temp1--;
				 temp--;
			}
			*current=val;
		}
		void remove(int value){
			current=arr;
			for(int i=0; i<size; i++){
				if (value==arr[i]){
					arr[i]=0;
				}
				
			}
		}
		
		void clear(){
			for(int i=0;i<size; i++){
				arr[i]=0;
				current=0;
				len=0;
				
			}
		}
		
		void print(){
			for(int i=0; i<size; i++){
				cout<<arr[i];
				cout<<endl;
			}
		}
		
		
};

int main(){
	
	list obj;
	obj.insert(3);
	obj.insert(5);
	obj.insert(6);
	obj.insert(9);
	obj.insert(11);
	obj.add(3,4);
	
//	obj.remove(6);
//	obj.clear();
	obj.print();
	return 0;
}

