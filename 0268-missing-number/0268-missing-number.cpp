class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Initialize ans with n (the size of the array)
        int ans = nums.size(); 
        
        // XOR ans with both the index and the value at that index
        for(int i = 0; i < nums.size(); i++) {
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};
/*int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long expectedSum = (long long)n * (n + 1) / 2;
        long long actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return (int)(expectedSum - actualSum);
    }
    */