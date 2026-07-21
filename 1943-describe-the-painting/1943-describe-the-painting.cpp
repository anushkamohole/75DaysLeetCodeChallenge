class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        // We use a map so we only process the exact points where changes happen.
        // Key = the point on the number line
        // Value = the + or - change to the color sum
        map<int, long long> diff;
        
        // STEP 1: PLACE THE BOUNDARIES
        for (const auto& segment : segments) {
            int start = segment[0];
            int end = segment[1];
            long long color = segment[2];
            
            diff[start] += color;    // Brush touches down
            diff[end] -= color;      // Brush lifts up (Off-switch at 'end')
        }
        
        // STEP 2: CALCULATE RUNNING TOTAL AND BUILD CHUNKS
        vector<vector<long long>> painting;
        long long running_total = 0;
        int prev_point = -1;
        
        // Loop through our map (it automatically goes from smallest point to largest)
        for (const auto& [current_point, color_change] : diff) {
            
            // If our running total is greater than 0, it means paint was on the paper
            // between the 'prev_point' and this 'current_point'.
            if (running_total > 0) {
                painting.push_back({prev_point, current_point, running_total});
            }
            
            // Update the running total with the + or - instruction at this point
            running_total += color_change;
            
            // This current point now becomes the start of the next potential chunk
            prev_point = current_point;
        }
        
        return painting;
    }
};