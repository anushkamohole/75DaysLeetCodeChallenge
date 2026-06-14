/*class Solution {
public:
    bool isPowerOfTwo(int n) {
        // __builtin_popcount counts the number of 1s in a 32-bit integer
        return n > 0 && __builtin_popcount(n) == 1;
    }
};
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Must be greater than 0, AND the bitwise trick must equal 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};