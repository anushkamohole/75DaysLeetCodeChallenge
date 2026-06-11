class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(') {
                // If depth is > 0, we are already inside a block. Keep it!
                if (depth > 0) {
                    result += c;
                }
                depth++; // Step deeper
            } 
            else if (c == ')') {
                depth--; // Step out
                
                // If depth is > 0 AFTER stepping out, it wasn't the final boundary. Keep it!
                if (depth > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};