#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j = 0;
    for (int i = 0; i< nums.size(); i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main(){
    vector<int> my_vector = {3, 2, 2, 3};
    int result = removeElement(my_vector, 3);
    cout << result;
    return 0;
}