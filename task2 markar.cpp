#include<iostream>
#include<string>
using namespace std;


// ############# PART-A #######################
////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
string  reverse_from_special_character(string str,char special, int index=0){
		string str1="";
		cout<<str[index];
		if(str[index]==special){
			//cout<<str[index]<<endl;
			return str1;
		}
		else{
			str1+=str[index];
			cout<<"str1 "<<str1[index];
			reverse_from_special_character(str,special,index+1);
			//cout<<" output of str1 "<<str1[index]<<endl;
		}
		//return str1;
	//	return str1;
}



////////  DO NOT CHANGE FUNCTION NAME AND PARAMTERS ///////
// ############# PART-B #######################
/*
    UNCOMMENT WHEN YOU DONE WITH PART A
int count_specific_number(string str, int num, int index=0){
    
}

*/






int main(){
  
    cout<<"Output "<<reverse_from_special_character("sabir.baloch",'.',0)<<endl;   
   // cout<<"Output:"<<count_specific_number("11112211119999912220000",9,0)<<endl;
    return 0;
}
