public class ExpSearch {
    static int binarySearch(int arr[], int target, int left, int right){
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (arr[mid]==target) {
                return mid;
            }else if (arr[mid] > target) {
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
    static int expsearch(int arr[], int target){
        if(arr[0] == target) return 0;
        int n = arr.length;
        int i = 1;
        while (i<n && arr[i]<=target) {
            i *=2;
        }
        return binarySearch(arr, target, i/2, Math.min(n-1, i));
    }
    
    public static void main(String[] args) {
        int arr[] = {1,2,4,5,6,7,8,9};
        int target = 9;
        int result = expsearch(arr, target);
        if (result != -1) {
            System.out.println("target found at index : "+result);
        }else{
            System.out.println("target not found.");
        }
    }
}
