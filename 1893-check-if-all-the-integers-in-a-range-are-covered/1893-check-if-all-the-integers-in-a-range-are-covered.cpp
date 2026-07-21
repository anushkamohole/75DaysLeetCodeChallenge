class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        // Constraints say numbers go up to 50. 
        // We need size 52 to handle index 51 (50 + 1) safely.
        vector<int> diff(52, 0);
        
        // 1. Mark the start and end of every interval
        for (const auto& range : ranges) {
            int start = range[0];
            int end = range[1];
            
            diff[start] += 1;       // Interval starts (pickup)
            diff[end + 1] -= 1;     // Interval ends (dropoff)
        }
        
        // 2. Keep a running total and check our target range
        int current_coverage = 0;
        
        for (int i = 1; i <= 50; ++i) {
            current_coverage += diff[i];
            
            // If we are inside the [left, right] window, we MUST have coverage
            if (i >= left && i <= right) {
                if (current_coverage == 0) {
                    return false; // Found a number with no covering interval
                }
            }
        }
        
        return true; // All numbers in [left, right] had a running total > 0
    }
};