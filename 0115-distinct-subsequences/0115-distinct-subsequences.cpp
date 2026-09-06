class Solution {
public:
    int numDistinct(string s, string t) {
        // Initialize a 2D vector 'memo' with dimensions [s.length()][t.length()]
        // Fill it entirely with -1 to indicate uncalculated states
        vector<vector<int>> memo(s.length(), vector<int>(t.length(), -1));
        
        return search(0, 0, s, t, memo);
    }

private:
    int search(int i, int j, const string& s, const string& t, vector<vector<int>>& memo) {
        // Base Cases
        if (j == t.length()) return 1; 
        if (i == s.length()) return 0; 
        
        // Memoization Check
        if (memo[i][j] != -1) return memo[i][j]; 
        
        // Make Choices
        if (s[i] == t[j]) {
            // Match: Add the paths where we USE the character and SKIP the character
            memo[i][j] = search(i + 1, j + 1, s, t, memo) + search(i + 1, j, s, t, memo);
        } else {
            // No Match: We must SKIP the current character in s
            memo[i][j] = search(i + 1, j, s, t, memo);
        }
        
        // Return the saved result for this specific (i, j) combination
        return memo[i][j];
    }
};