class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        // 1 << n is the exact same as 2^n. 
        // If n = 3, 1 << 3 shifts '1' left by 3 bits, giving 1000 in binary (which is 8).
        int subsetCount = 1 << n; 
        
        vector<vector<int>> result;

        // Loop through all numbers from 0 to (2^n - 1)
        for (int i = 0; i < subsetCount; i++) {
            vector<int> currentSubset;
            
            // For each number 'i', check all 'n' bits to see which are set to 1
            for (int j = 0; j < n; j++) {
                
                // (1 << j) creates a number with only the j-th bit set (e.g., 001, 010, 100)
                // i & (1 << j) checks if the j-th bit in 'i' is also 1
                if (i & (1 << j)) {
                    currentSubset.push_back(nums[j]);
                }
            }
            
            result.push_back(currentSubset);
        }
        
        return result;
    }
};