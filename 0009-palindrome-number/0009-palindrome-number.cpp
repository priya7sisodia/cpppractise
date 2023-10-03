class Solution {
public:
    bool isPalindrome(int x) {
        // If x is negative or ends with 0 but is not 0 itself, it cannot be a palindrome.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // When the length of the remaining number is odd, we can remove the middle digit.
        // For example, in the number 12321, we can remove the middle '3'.
        return x == reversed || x == reversed / 10;
    }
};
