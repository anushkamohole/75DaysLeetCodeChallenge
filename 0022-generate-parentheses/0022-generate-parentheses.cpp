class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
        // Base case: the current string length reaches 2 * n
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        // Add an opening parenthesis if we haven't reached 'n' open brackets
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back(); // backtrack
        }

        // Add a closing parenthesis if it won't exceed the number of open brackets
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back(); // backtrack
        }
    }
};