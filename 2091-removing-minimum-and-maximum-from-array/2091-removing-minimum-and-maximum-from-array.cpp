class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0;
        int maxIdx = 0;

        // Step 1: Find indices of minimum and maximum elements
        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        // Let i be the smaller index, j be the larger index
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        // Step 2: Calculate the 3 possible strategies
        int bothFront = j + 1;
        int bothBack = n - i;
        int bothSides = (i + 1) + (n - j);

        // Step 3: Return the minimum of all 3 strategies
        return min({bothFront, bothBack, bothSides});
    }
};