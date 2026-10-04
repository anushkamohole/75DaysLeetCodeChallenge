class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;

        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--; // Assume '*' is ')'
                max_open++; // Assume '*' is '('
            }

            // If max_open < 0, there are too many ')' to ever balance
            if (max_open < 0) return false;

            // min_open cannot drop below 0 because '*' can simply be ""
            if (min_open < 0) min_open = 0;
        }

        return min_open == 0;
    }
};