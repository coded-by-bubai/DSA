#include<iostream>
using namespace std;
int MostWater(int arr[], int n){
    int maxWater = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int w = j-i;
            int ht = (arr[i] > arr[j]) ? arr[j] : arr[i];
            int water = w*ht;
            maxWater = (water > maxWater)? water : maxWater;
        }
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