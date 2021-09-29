#include<iostream>
#include<string>
using namespace std;

int count_specific_number(string str, int num, int index=0){
    int count=0;
    if(str[index]=='\0'){
        return count;
    }else{
        count += count_specific_number(str,num,index+1);
      	if((int(str[index])-48)==num){
            count++;
        }
        return count;
    }

}


int main(){
    //string s;
    int sum=0;
  
    //string s=reverse_from_special_character(".abcdef.sdssd",'.',0);
   // cout<<s;
    cout<<count_specific_number("Welcome to 20000021!",0,0);
    //cout<<"Output:"<<sum;
    return 0;
}
