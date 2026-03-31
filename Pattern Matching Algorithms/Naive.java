public class Naive {
    static int patternMatch(String text, String patt){
        int n = text.length();
        int m = patt.length();
        for (int i = 0; i <= n-m; i++) {
            int j = 0;
            while (j<m && text.charAt(i+j) == patt.charAt(j)) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        String text = "abaacaabad";
        String patt = "bad";
        int result = patternMatch(text, patt);
        if (result!=-1) {
            System.out.println("Pattern found at index "+result);
        }else{
            System.out.println("pattern not found");
        }
    }
}
