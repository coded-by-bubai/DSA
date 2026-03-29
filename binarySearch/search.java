class search {
    static int binarySearch(int arr[], int target){
        int left = 0;
        int right = arr.length - 1;
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
    static int binarySearchRE(int arr[], int target, int left, int right){
        if (left>right) {
            return -1;
        }
        int mid = left + (right - left)/2;
        if (arr[mid]==target) {
            return mid;
        }
        else if (arr[mid] > target) {
            return binarySearchRE(arr, target, left, mid - 1);
        }
        else{
            return binarySearchRE(arr, target, mid + 1, right);
        }
        
    }
    
    public static void main(String[] args) {
        int arr[] = {1,2,4,5,6,7,8,9};
        int target = 5;
        int result = binarySearchRE(arr, target, 0, arr.length-1);
        if (result != -1) {
            System.out.println("target found at index : "+result);
        }else{
            System.out.println("target not found.");
        }
    }
}
