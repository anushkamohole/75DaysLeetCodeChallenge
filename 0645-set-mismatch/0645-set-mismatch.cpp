class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0); // Tally sheet for numbers 1 to n
        int duplicate = -1, missing = -1;
        
        // Count how many times each number appears
        for (int num : nums) {
            count[num]++;
        }
        
        // Check our tally sheet
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) duplicate = i;
            if (count[i] == 0) missing = i;
        }
        
        return {duplicate, missing};
    }
};