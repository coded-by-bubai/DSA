#include<iostream>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalCost = 0;
    int totalGas = 0;

    int n = gas.size();
    int currentGas = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += (gas[i] - cost[i]);

        if(currentGas < 0){
            start = i+1;
            currentGas = 0;
        }
    }
    return (totalGas < totalCost) ? -1 : start;
}

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int res = canCompleteCircuit(gas, cost);
    if (res != -1){
        cout << "start index is " << res;
    }else{
        cout << "Not possible";
    }
    return 0;
}