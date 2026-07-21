class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // The problem constraints state locations are between 0 and 1000.
        // We create an array of size 1001 to cover all possible locations.
        vector<int> diff(1001, 0);
        
        // STEP 1: PLACE THE BOUNDARIES
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            diff[from] += numPassengers; // Passengers get in
            diff[to] -= numPassengers;   // Passengers get out (Off-switch is exactly at 'to')
        }
        
        // STEP 2: CALCULATE RUNNING TOTAL
        int running_total = 0;
        
        for (int i = 0; i <= 1000; i++) {
            running_total = running_total + diff[i];
            
            // If the number of passengers in the car exceeds capacity, we fail.
            if (running_total > capacity) {
                return false;
            }
        }
        
        // If we made it through every location without exceeding capacity, we succeed.
        return true;
    }
};