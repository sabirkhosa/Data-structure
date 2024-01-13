#include<iostream>
#include<string>
using namespace std;

// Function to reverse a string until a special character is encountered
string reverse(string str, char special, int index = 0) {
    string str1 = "";

    // Base case: stop recursion when the special character is encountered
    if (str[index] == special) {
        return str1;
    } else {
        // Recursive call: reverse the remaining part of the string
        str1 += reverse(str, special, index + 1);

        // Append the current character to the reversed string
        str1 += str[index];

        // Return the reversed string
        return str1;
    }
}

int main() {
    // Example usage: reverse the string "Hello Dorothy$ nice to see you" until '$'
    string s = reverse("Hello Dorothy$ nice to see you", '$', 0);

    // Print the reversed string
    cout << s << endl;

    return 0;
}
