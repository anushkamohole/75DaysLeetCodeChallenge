class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // We create an array of size n + 1. 
        // This gives us n slots for the flights, plus 1 extra slot at the end
        // so our 'last' off-switch doesn't go out of bounds if a booking goes up to the final flight.
        vector<int> diff(n + 1, 0);
        
        // STEP 1: PLACE THE BOUNDARIES
        for (const auto& booking : bookings) {
            int first = booking[0] - 1; // Convert to 0-based index
            int last = booking[1] - 1;  // Convert to 0-based index
            int seats = booking[2];
            
            diff[first] += seats;       // Start reserving seats
            diff[last + 1] -= seats;    // Stop reserving seats (Off-switch)
        }
        
        // STEP 2: CALCULATE RUNNING TOTAL
        vector<int> answer(n);
        int running_total = 0;
        
        for (int i = 0; i < n; i++) {
            running_total = running_total + diff[i];
            answer[i] = running_total;
        }
        
        return answer;
    }
};