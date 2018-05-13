public class Solution {
    public String longestPalindrome(String s) {
        if (s.isEmpty()) return "";
        else if (s.length() == 1) return s;
        int start = 0, end = 0, max = 1;
        for (int i = 0; i < s.length();) {
            if ((s.length() - i) <= max / 2) break;
            int k = i, j = i;
            while (k < s.length() - 1 && s.charAt(k) == s.charAt(k + 1)) k++;
            i = k + 1;
            while (k < s.length() - 1 && j > 0 && s.charAt(k + 1) == s.charAt(j - 1)) {
                j--;
                k++;
            }
            int len = k - j + 1;
            if (len > max) {
                start = j;
                end = k;
                max = len;
            } 
        }
        return s.substring(start, end + 1);
    }
}