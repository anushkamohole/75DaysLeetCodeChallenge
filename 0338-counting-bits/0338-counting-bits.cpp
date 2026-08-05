class Solution {
public:
    vector<int> countBits(int n) {
        // Create an array of size n + 1, filled with zeros
        vector<int> ans(n + 1, 0);
        
        // We start at 1 because ans[0] is always 0
        for (int i = 1; i <= n; i++) {
            
            
            // ans[i] = (Answer for the pushed-right version) + (What was on the edge)
            ans[i] = ans[i >> 1] + (i & 1);
            
        }
        
        return ans;
    }
};