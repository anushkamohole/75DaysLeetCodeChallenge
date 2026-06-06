class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        // Loop until st and end point to the exact same element
        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end]) {
                // The drop is to the right. mid is definitely NOT the minimum.
                st = mid + 1;
            } else {
                // The right side is sorted. The minimum is mid, or to its left.
                // We DO NOT do mid - 1, because mid itself might be the minimum!
                end = mid; 
            }
        }

        // When st == end, we have narrowed down to one single element.
        return nums[st];
    }
};