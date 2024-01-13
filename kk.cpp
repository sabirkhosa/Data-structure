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
        }#include<iostream>
#include<string>
using namespace std;

// Function to count occurrences of a specific number in a string
int count_specific_number(string str, int num, int index = 0) {
    int count = 0;

    // Base case: end of the string is reached
    if (str[index] == '\0') {
        return count;
    } else {
        // Recursive case
        count += count_specific_number(str, num, index + 1);

        // Check if the current character is the specified number
        if ((int(str[index]) - 48) == num) {
            count++;
        }

        return count;
    }
}

int main() {
    int sum = 0;

    // Example usage of the count_specific_number function
    cout << count_specific_number("Welcome to 20000021!", 0, 0);

    return 0;
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
