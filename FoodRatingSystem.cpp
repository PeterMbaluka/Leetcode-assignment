#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int popcount(int x) {
        return __builtin_popcount(x); // GCC/Clang builtin
    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        // Step 1: remove duplicates
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> bits;
        bits.reserve(s.size());

        // Step 2: compute popcounts
        for (int x : s) bits.push_back(popcount(x));

        // Step 3: sort popcounts
        sort(bits.begin(), bits.end());
        int n = bits.size();
        long long ans = 0;

        // Step 4: for each i, binary search
        for (int i = 0; i < n; i++) {
            int need = k - bits[i];
            int j = lower_bound(bits.begin(), bits.end(), need) - bits.begin();
            ans += (n - j); // all j..n-1 valid
        }
        return ans;
    }
};

