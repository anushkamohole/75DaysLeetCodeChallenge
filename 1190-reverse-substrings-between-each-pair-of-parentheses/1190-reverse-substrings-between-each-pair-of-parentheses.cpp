class Solution {
public:
    string reverseParentheses(string s) {
        string stack;
        
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                
                // Pop characters until we hit the matching '('
                while (!stack.empty() && stack.back() != '(') {
                    temp += stack.back();
                    stack.pop_back();
                }
                
                // Pop the '(' itself
                if (!stack.empty()) {
                    stack.pop_back(); 
                }
                
                // Push the reversed characters back onto the stack
                stack += temp; 
            } else {
                // Push letters and '(' normally
                stack.push_back(c);
            }
        }
        
        return stack;
    }
};