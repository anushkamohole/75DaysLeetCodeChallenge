class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible sum for 'num' digits
        if ((long long)num * 9 < sum) {
            return "";
        }
        
        int nines = sum / 9;
        int remainder = sum % 9;
        
        string result = "";
        
        // 1. Append as many 9s as possible to maximize the score and leading digits
        result.append(nines, '9');
        
        // 2. Append the remainder digit if it exists
        if (remainder > 0) {
            result.push_back('0' + remainder);
        }
        
        // 3. Pad the rest of the positions with '0' to ensure exact length 'num'
        while (result.length() < num) {
            result.push_back('0');
        }
        
        return result;
    }
};