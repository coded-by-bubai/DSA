#include<iostream>

using namespace std;

bool isValid(string s) {
    int top = -1;
    int n = s.size();

    for(int i=0; i<n; i++){
        char c = s[i];

        if(c=='(' || c=='{' || c=='['){
            s[++top] = s[i];
        }
        else if(c==')' || c=='}' || c==']'){
            if(top==-1) return false;
            char t = s[top];
            if(c==')' && t!='(' || c=='}' && t!='{' || c==']' && t!='['){
                return false;
            }
            
            top--;
        }
        
    }
    return top == -1;
}

int main(){
    string str = "(){}[]";
    cout << (isValid(str) ? "Valid" : "Invalid");
    return 0;
}