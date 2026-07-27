/*
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/
#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(int x) {
    string y = to_string(x);
    int n = y.length();
    for (int i = 0; i < n/2; i++){
        if(y[i] != y[n-i-1]) return false;
    }
    return true;
}

int main(){
    int number;
    cout << "Enter a integer: " ;
    cin >> number;
    cout << (isPalindrome(number) ? "True" : "False") ;
}