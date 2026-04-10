#include<iostream>
#include<vector>

using namespace std;

void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        if (arr[j] <= key) continue;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        
    }
    
    
}
int main(){
    int arr[] = {2, 5, 7, 4, 6, 1, 10, 8, 9, 3};
    cout << "unsorted array: ";
    for (int val : arr)
    {
        cout << val <<" ";
    }
    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    cout <<endl<< "sorted array: ";
    for (int val : arr)
    {
        cout << val<<" ";
    }
    return 0;
}