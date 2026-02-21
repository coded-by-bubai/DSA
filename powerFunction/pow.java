package powerFunction;
public class pow{
    /* pow(2,5) 
    bin(5) == 101
    every step we double base (here base = 2)
    1 -> 2^1    ans = 2^1
    0 -> 2^2    ans = 2^1
    1 -> 2^4    ans = 2^1 * 2^4 = 2^5
    .
    .
    .
    we solve this in 3 iterations = (log2 5 ) + 1 which means O(log n)
    so we reduce the iterations from 5 to 3
    */
   public static double powerBrute(double a, int k) {

        if (k == 0) return 1.0;

        long exponent = Math.abs((long) k);
        double result = 1.0;

        for (long i = 0; i < exponent; i++) {
            result *= a;
        }

        if (k < 0) {
            return 1.0 / result;
        }

        return result;
    }
    
    public static double power(double a, int k){
        long binaryForm = k;
        double x = a;
        double ans = 1;
        if (a == 0) return 0.0;
        if (k == 0) return 1.0;
        if (a == 1) return 1.0;
        if (a == -1 && k%2 == 0) return 1.0;
        if (a == 1 && k%2 != 0) return -1.0;
        if (k < 0) {
            x = 1/x;
            binaryForm = -binaryForm;
        }
        while (binaryForm > 0){
            if (binaryForm % 2 == 1) {
                ans *= x;
            }
            x = x * x;
            binaryForm /= 2;
        }
        return ans;
    }
    public static void main(String[] args) {
        System.out.print(power(2,3));
    }
}