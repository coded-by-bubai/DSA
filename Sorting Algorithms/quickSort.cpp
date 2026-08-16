#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, int l, int h){
    int pivot = arr[h];

    int i = l-1;
    for(int j = l; j<=h-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);

    return i+1;
}

void quicksort(vector<int>& arr, int l, int h){
    if(l<h){
        int pi = partition(arr, l, h);

        quicksort(arr, l, pi-1);
        quicksort(arr, pi+1, h);
    }
}

int main(){
    vector<int> arr = {10,50,2,7,9,4,6,1,5,4,10};
    cout << "Original: ";
    for(int x:arr)
    cout<<x  << " ";
    cout << endl;
    quicksort(arr, 0 , arr.size() - 1);
    cout << "Sort: ";
    for(int x:arr)
        cout<<x  << " ";
    return 0;
}