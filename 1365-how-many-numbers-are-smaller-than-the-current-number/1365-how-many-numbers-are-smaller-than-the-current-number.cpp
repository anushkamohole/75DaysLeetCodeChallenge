class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 1. Make a copy to sort, preserving the original 'nums'
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        
        // 2. Map each number to its first appearance index
        unordered_map<int, int> countMap;
        for (int i = 0; i < sortedNums.size(); i++) {
            // Only record it if we haven't seen it yet (handles duplicates)
            if (countMap.find(sortedNums[i]) == countMap.end()) {
                countMap[sortedNums[i]] = i;
            }
        }
        
        // 3. Build the final answer based on the original array
        vector<int> result;
        for (int num : nums) {
            result.push_back(countMap[num]);
        }
        
        return result;
    }
};