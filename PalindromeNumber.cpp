class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindrome
        if (x < 0) return false;

        // Numbers ending in 0 (but not 0 itself) can't be palindrome
        if (x % 10 == 0 && x != 0) return false;

        long reversed = 0, original = x;
        while (x > 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};

