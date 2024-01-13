#include<iostream>
#include<string>
#include<sstream>
using namespace std;

// Function to convert an integer to a string
string int_to_string(int x){
    stringstream ss;
    ss << x;
    return ss.str();
}

// Function to add a zero to the end of an integer and return it as a string
string add_zero(int x){
    string str1 = int_to_string(x);
    char str2 = '0';
    str1 += str2;
    return str1;
}

// Function to convert a string to an integer
int string_to_int(string x){
    stringstream degree(x);
    int y = 0;
    degree >> y;
    return y;
}

// Function to calculate x raised to the power y
int power(int x, int y){
    if(y == 0){
        return 1;
    }
    return x * power(x, y - 1);
}

// Function that seems to concatenate a zero to the end of x
int function(int x, int y){
    // Add a zero to the end of x
    string str1 = add_zero(x);
    // Convert the modified string back to an integer
    int num1 = string_to_int(str1);
    return num1;
}

int main(){
    int x, y;

    // Get input values for x and y
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;

    // Calculate x^y using recursion
    int a = power(x, y);
    cout << "Power is: " << a << endl;

    // Call the function that adds a zero to the end of x and converts it to an integer
    int b = function(x, y);
    cout << "After concatenation: " << b;

    return 0;
}
