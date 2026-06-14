class Solution {
public:
    bool isPowerOfTwo(int n) {
        // __builtin_popcount counts the number of 1s in a 32-bit integer
        return n > 0 && __builtin_popcount(n) == 1;
    }
};