class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); i++) {
            // Case 1: Current interval is strictly before newInterval
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            }
            // Case 2: Current interval is strictly after newInterval
            else if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                
                // Append the remaining intervals using iterators and return
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            // Case 3: Overlap exists, merge them into newInterval
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        
        // If the loop finishes without returning, newInterval belongs at the very end
        res.push_back(newInterval);
        
        return res;
    } 
    
};