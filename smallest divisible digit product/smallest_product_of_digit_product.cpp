#include<iostream>

using namespace std;

int smallestNumber(int n, int t) {
    
    for(int current = n; ; current++){
        int digiprod = 1;

        int temp = current;
        while(temp>0){
            int rem = temp % 10;
            digiprod *= rem;
            temp /= 10;
        }

        if(digiprod % t == 0) return current;
    }
}

int main(){
    cout<<smallestNumber(15, 3);
    return 0;
}