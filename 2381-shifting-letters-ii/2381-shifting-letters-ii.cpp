class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        
        // Create the difference array with one extra space for the "end + 1" boundary
        vector<int> diff(n + 1, 0);
        
        // STEP 1: PLACE THE BOUNDARIES
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            if (direction == 1) {
                diff[start] += 1;          // Start adding 1
                diff[end + 1] -= 1;        // Stop adding 1
            } else {
                diff[start] -= 1;          // Start subtracting 1
                diff[end + 1] += 1;        // Stop subtracting 1
            }
        }
        
        // STEP 2: CALCULATE RUNNING TOTAL AND SHIFT LETTERS
        int running_total = 0;
        
        for (int i = 0; i < n; i++) {
            // Calculate the running total exactly like we practiced
            running_total = running_total + diff[i];
            
            // Simplify the massive running total to a number between 0 and 25.
            // The formula (val % 26 + 26) % 26 handles negative numbers properly in C++.
            int net_shift = (running_total % 26 + 26) % 26;
            
            // Apply the shift to the character at index i
            s[i] = 'a' + (s[i] - 'a' + net_shift) % 26;
        }
        
        return s;
    }
};