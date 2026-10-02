class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        //Sort intervals based on their start times
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        //Iterate through intervals and merge overlapping ones
        for (const auto& interval : intervals) {
            // If the merged list is empty, or if the current interval does not overlap with the previous one, append it
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // There is an overlap, so merge the current interval with the previous one
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};