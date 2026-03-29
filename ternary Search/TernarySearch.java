public class TernarySearch {
    static int ternarySearch(int arr[], int target){
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid1 = left + (right - left)/3;
            int mid2 = right - (right - left)/3;
            if (arr[mid1]==target) {
                return mid1;
            }
            if (arr[mid2] == target) {
                return mid2;
            }
            
            if (arr[mid1]>target) {
                right = mid1 - 1;
            }
            else if (arr[mid2]<target) {
                left = mid2 + 1;
            }
            else{
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int arr[] = {1,2,4,5,6,7,8,9};
        int target = 9;
        int result = ternarySearch(arr, target);
        if (result != -1) {
            System.out.println("target found at index : "+result);
        }else{
            System.out.println("target not found.");
        }
    }
}
