class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;   // last digit (can be negative if x < 0)
            x /= 10;

            // Check for overflow before doing rev = rev * 10 + pop
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }
};
