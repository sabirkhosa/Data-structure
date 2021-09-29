#include<iostream>
using namespace std;
int getlength(char *ch,char *ptr,int count){
	if (*ptr=='\0'){
			return count;
}
		
		else{
			
			ptr++;
			count=count+1;
			
	return	getlength(ch,ptr,count);
		
			
	}
	

}
int finddecimal(char *ch,char *ptr,int index){
	if (*ptr=='.'){
		return index;
	}
	else{
		ptr++;
		index=index+1;
		return finddecimal(ch,ptr,index);
	}
}


int main(){
    char *ch = "22222.222222222";
    char *ptr=NULL;
    ptr=ch;
	int x;
	int y;
	int count=0;
	int index=1;
	x=getlength(ch,ptr,count);
	y=finddecimal(ch,ptr,index);
	cout <<"length is :"<<x<<endl;
	cout<<"decimal is at position :"<<y<<endl;
	return 0;
}
