class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        // Loop until st and end point to the exact same element
        while (st < end) {
            int mid = st + (end - st) / 2;

            // Trick: Force 'mid' to always be an EVEN index
            if (mid % 2 == 1) {
                mid--; 
            }

            // Since mid is even, its pair SHOULD be at mid + 1
            if (nums[mid] == nums[mid + 1]) {
                // Pattern is intact! The single element is further right.
                // We skip past this matched pair (+2).
                st = mid + 2;
            } else {
                // Pattern is broken! The single element is mid, or further left.
                end = mid;
            }
        }

        // When st == end, we've found the single element
        return nums[st];
    }
};