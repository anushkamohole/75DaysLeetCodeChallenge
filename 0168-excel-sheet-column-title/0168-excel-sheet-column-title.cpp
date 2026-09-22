class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Shift from 1-based to 0-based
            
            char ch = 'A' + (columnNumber % 26);
            result += ch;
            
            columnNumber /= 26;
        }
        
        //reverse
        reverse(result.begin(), result.end());
        return result;
    }
};