class Solution {
private:
    bool canSplit(const vector<int>& nums, int k, int max_sum) {
        int subarrays_needed = 1;
        int current_sum = 0;
        
        for (int num : nums) {
            if (current_sum + num > max_sum) {
                subarrays_needed++;
                current_sum = num;
            } else {
                current_sum += num;
            }
        }
        
        return subarrays_needed <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canSplit(nums, k, mid)) {
                result = mid;
                high = mid - 1; // Try to find a smaller valid maximum sum
            } else {
                low = mid + 1;  // Increase mid since mid sum was too small
            }
        }
        
        return result;
    }
};