#include<iostream>
using namespace std;

class list{
	public: 
		int *arr,*temp,*a;
		int x,y,size;
		list(){
			arr=temp=NULL;
		}
		void MostFrequentElementInSubArray(int left, int right, int freq){
			cout<<"enter the size of array: ";
			cin>>size;
			arr=new int[size];
			temp=arr;
			for(int i=0; i<size; i++){
				cin>>*temp;
				temp++;
			}
			
			a = new int[right];
			for(int i = 0 ; i< right ; i++){
				a[i] = NULL;
			}
			
			int counter = 0;
			int index = 0;
			int flag = 0;
			for (int i = 0 ; i <= right ; i++){
				for (int k = 0 ; k < right ; k++){
					if(a[k] == arr[i]){
						flag = 1;
						break;
					}
				}
				if (flag == 1){
					flag = 0;
					continue;
					
				}
				for (int j = 0 ; j <= right ; j++){
					if (arr[i] == arr[j]){
						counter++;
					}
					if (counter >= freq){
						a[index] = arr[i];
						counter = 0;
						index++;
					}
				}
			}
			
		for (int i = 0 ; i < right ; i++){
			if (a[i] == NULL){
				break;
		}else{
			cout<<"output : "<<a[i]<<endl;
		}
		}
			
		}
		
};

int main(){
	/*
	list obj;
	int left,right,freq;
	cout<<"left ";
	cin>>left;
	cout<<"right ";
	cin>>right;
	cout<<"frequent ";
	cin>>freq;
	obj.MostFrequentElementInSubArray(left,right,freq);
	return 0;
	*/
	int a=8;
	cout<<"after divide "<<10/10;
}
