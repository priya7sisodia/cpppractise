class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() > haystack.length()) return -1;

        // using KMP pattern matching algorithm

        int[] lps = new int[needle.length()];
        computeLPSArray(needle, lps);

        int i = 0, j = 0;
        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
            }

            else {
                if (j == 0) i++;
                else j = lps[j - 1];
            }

            if (j == needle.length()) return i - needle.length();
        }

        return -1;
    }


    private void computeLPSArray(String needle, int[] lps) {
        int len = 0;
        int i = 1;

        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }

                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
}