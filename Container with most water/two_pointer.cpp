#include<iostream>
using namespace std;
int MostWater(int arr[], int n){
    int maxWater = 0;
    int lp = 0, rp = n-1;
    while (lp < rp)
    {
        int ht = min(arr[lp], arr[rp]);
        int w = rp - lp;
        int currWatter = ht * w;
        maxWater = max(currWatter, maxWater);

        arr[lp] < arr[rp] ? lp++ : rp--;
    }
    
    return maxWater;
    
}
int main(){
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height)/sizeof(height[0]);
    int most_water = MostWater(height,n);
    cout << "container with most water is " << most_water ;;
    return 0;
}