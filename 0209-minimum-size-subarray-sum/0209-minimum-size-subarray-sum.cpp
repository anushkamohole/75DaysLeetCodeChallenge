class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLen = INT_MAX; 

        for (int right = 0; right < nums.size(); right++) {
            // 1. Expand the window by adding the current number to our running sum
            currentSum += nums[right];

            // 2. Shrink the window: 
            // As long as our window is valid (sum >= target), try to make it smaller
            while (currentSum >= target) {
                // Record the size of the current valid window
                minLen = min(minLen, right - left + 1);
                
                // Kick out the left-most number and shrink the window
                currentSum -= nums[left];
                left++;
            }
        }

        // If minLen is still INT_MAX, we never hit the target sum, so return 0
        return minLen == INT_MAX ? 0 : minLen;
    }
};