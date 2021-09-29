#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string int_to_string(int x){
	stringstream ss;
	ss <<x;
	return ss.str();
}

string add_zero(int x){
	string str1=int_to_string(x);
	char str2='0';
	str1+=str2;
	return str1;
}

int string_to_int(string x){
	stringstream degree(x);
	int y=0;
	degree>>y;
	return y;
}


int power(int x,int y){
	if(y==0){
		return 1;
	}
	
	return x*power(x,y-1);
}

  int function(int x,int y){
	int shift,result;
	string str1=add_zero(x);
//	string s=int_to_string(x);
	//string str1=add_zero()
	int num1=string_to_int(str1);
	return num1;
 }






int main(){
	int x,y;
	cout<<"enter value of x :";
	cin>>x;
	cout<<"enter value of y :";
	cin>>y;
	
	//int z=function(x,y);
	int a=power(x,y);
	cout<<"power is "<<a<<endl;
	int b=function(x,y);
	cout<<"after conacatenation is "<<b;
//	int z=add_zero(x);
//	cout<<"after adding zero is "<<z;
	
	return 0;
}
