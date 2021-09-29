#include<iostream>
#include<string>
using namespace std;

string reverse(string str,char special,int index=0){
    string str1="";
    if(str[index]==special){ 
      return str1;
    }
    else{
    str1+= reverse(str,special,index+1);
    str1 += str[index];
    return str1;
    
}

}

int main(){
    string s = reverse("Hello Dorothy$ nice to see you",'$',0);
    cout<<s<<endl;
    return 0;
}
