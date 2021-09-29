#include<iostream>
#include<cmath>
using namespace std;


int main(){
	int *arr;
	int index=0;
	cout<<"size of array ";
	cin>>index;
	arr=new int[index];
	int *temp=arr;
	int *temp1=arr;
	for(int i=0;i<index; i++){
		cin>>*temp;
		temp++;
	}
	temp1=arr;
	for(int i=0;i<index-1; i++){
		temp1++;
	}
	temp=arr;
	for(int i=0; i<index/2;i++){
		if(*temp==*temp1){
			temp1--;
			temp++;
		}
		else{
			cout<<"not a palyndrome ";
			break;
		}
		if(temp==temp1){
			cout<<"palyndrome";
			break;
		}
	}
	return 0;
}
