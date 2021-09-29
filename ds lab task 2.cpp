#include<iostream>
using namespace std;


int main(){
	int size=6;
	int *arr=new int[size];
	int *ptr=NULL;
	int *ptr1 = NULL;
	ptr=arr;
	cout<<"enter the values of array :"<<endl;
	for(int i=0; i<size; i++){
		cin >> *ptr;
		ptr++;
	}
	cout<<"array_list = ";
	ptr = arr;
	for (int i =0 ; i<size ;i ++){
		cout<<*ptr <<" ";
		ptr++;
	}
	int target = 15;
	ptr1 = ptr = arr;
	int sum;
	int flag = 0;
	for(int i = 0 ; i < size ; i++){
		for (int j = 0 ; j < size ; j++){
			sum = *ptr + *ptr1;
			if (sum == target){
				flag = 1;
				break;
			}
			ptr1++;
		}
		if (flag == 1){
			break;

		}
		ptr1 = arr;
		ptr++;		
	}
	cout<<endl<<"output : "<< *ptr << "," << *ptr1 <<endl;
	return 0;
}
