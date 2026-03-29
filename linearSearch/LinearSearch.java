class LinearSearch {
    static int linear(int arr[],int target ){
        for (int i = 0; i<arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        int arr[] = {2,4,7,5,8,9,6,1};
        int target = 5;
        int result = linear(arr, target);
        if (result != -1) {
            System.out.println("target found at index : "+result);
        }else{
            System.out.println("target not found.");
        }
    }
}