class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> freq;

        // Step 1: count frequency
        for(int num : nums){
            freq[num]++;
        }

        // Step 2: bucket
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it : freq){
            int num = it.first;
            int f = it.second;
            bucket[f].push_back(num);
        }

        // Step 3: collect top k
        vector<int> ans;

        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }

        return ans;
    }
};