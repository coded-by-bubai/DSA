public class kmp {
    static int[] lps(String pattern){
        int[] result = new int[pattern.length()];
        int pre = 0, suff = 1;
        result[0]=0;
        while (suff < pattern.length()) {
            //matched
            if (pattern.charAt(pre) == pattern.charAt(suff)) {
                result[suff] = pre+1;
                pre++;
                suff++;
            }
            //unmatched
            else{
                if (pre == 0) {
                    result[suff] = 0;
                    suff++;
                } else {
                    pre = result[pre - 1];
                }
            }
        }
        return result;
    }
    static int kmpAlgo(String text, String patt){
        int[] lpsArr = lps(patt);
        int i = 0, j = 0;
        while (i<text.length() && j <patt.length()) {
            if (text.charAt(i) == patt.charAt(j)) {
                i++;
                j++;
            }
            else{
                if (j == 0) {
                    i++;
                }else{
                    j = lpsArr[j-1];
                }
            }
        }
        if (j == patt.length()) {
            return i-j;
        }
        return -1;
    }
    public static void main(String[] args) {
        String text = "abaacaabad";
        String patt = "d";
        int result = kmpAlgo(text, patt);
        if (result!=-1) {
            System.out.println("Pattern found at index "+result);
        }else{
            System.out.println("pattern not found");
        }
    }
}
