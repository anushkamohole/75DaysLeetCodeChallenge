class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        // We use st < end because we are comparing mid to mid + 1
        // This ensures mid + 1 never goes out of bounds.
        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // The slope is rising. A peak MUST exist to the right.
                st = mid + 1;
            } else {
                // The slope is falling (or flat). A peak MUST exist to the left (including mid).
                end = mid;
            }
        }
        // When st == end, we have successfully trapped a peak element.
        return st; 
    }
};