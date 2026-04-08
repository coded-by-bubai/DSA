#include<iostream>
#include<vector>

using namespace std;

void selection_sort(int arr[], int n){
    
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    
}
int main(){
    int arr[] = {2, 5, 7, 4, 6, 1, 10, 8, 9, 3};
    cout << "unsorted array: ";
    for (int val : arr)
    {
        cout << val <<" ";
    }
    selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
    cout <<endl<< "sorted array: ";
    for (int val : arr)
    {
        cout << val<<" ";
    }
    return 0;
}