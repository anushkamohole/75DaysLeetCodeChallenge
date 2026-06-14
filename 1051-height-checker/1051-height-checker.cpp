class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        // 1. Create the 'expected' array by copying the original 'heights'
        vector<int> expected = heights;
        
        // 2. Sort the 'expected' array so it represents the correct order
        sort(expected.begin(), expected.end());
        
        int count = 0;
        
        // 3. Compare both arrays index by index
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != expected[i]) {
                count++;
            }
        }
        
        return count;
    }
};