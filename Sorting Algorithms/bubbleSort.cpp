#include <iostream>
#include<vector>

using namespace std;

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(!swapped) break;
        
    }
    
}

int main()
{
    int arr[] = {2, 5, 7, 4, 6, 1, 10, 8, 9, 3};
    cout << "unsorted array: ";
    for (int val : arr)
    {
        cout << val <<" ";
    }
    bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
    cout <<endl<< "sorted array: ";
    for (int val : arr)
    {
        cout << val<<" ";
    }
    return 0;
}