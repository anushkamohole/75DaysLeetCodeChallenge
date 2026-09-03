class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_odd = false;

        // Find the minimum value and check if any odds exist
        for (int num : nums1) {
            if (num < min_val) {
                min_val = num;
            }
            if (num % 2 != 0) {
                has_odd = true;
            }
        }

        // If the smallest number is even, we fail if there are any odd numbers
        if (min_val % 2 == 0 && has_odd) {
            return false;
        }

        // Otherwise, it's either all even already, or min_val is odd
        return true;
    }
};