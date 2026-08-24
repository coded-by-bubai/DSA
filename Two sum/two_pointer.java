import java.util.Arrays;
public class two_pointer {
    static int[] twoSum(int[] arr, int tar){
        int n = arr.length;
        int i = 0, j = n-1;
        Arrays.sort(arr);

        while(i<j){
            int sum = arr[i] + arr[j];

            if(sum == tar){
                return new int[]{arr[i],arr[j]};
            }
            else if(sum < tar){
                i++;
            }
            else{
                j--;
            }
        }
        return new int[]{};
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 11, 7, 1};
        int[] res = twoSum(arr, 9);
        if(res.length != 0){
            System.out.println("Value : "+res[0]+" "+res[1]);
        }
        else{
            System.out.println("No Solution Found.");
        }
    }
}
