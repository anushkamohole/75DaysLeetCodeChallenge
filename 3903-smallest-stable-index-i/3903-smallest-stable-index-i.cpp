class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        //Precompute suffix minimums
        vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = min(nums[i], suff_min[i + 1]);
        }
        
        //Maintain running prefix max and check stability
        int pref_max = nums[0];
        
        for (int i = 0; i < n; ++i) {
            pref_max = max(pref_max, nums[i]);
            
            // Check the instability score
            if (pref_max - suff_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
    
};