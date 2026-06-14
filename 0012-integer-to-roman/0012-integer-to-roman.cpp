class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string roman = "";
        
        for (const auto& pair : romanMap) {
            while (num >= pair.first) {
                roman += pair.second;  // Append the Roman symbol (e.g., "M")
                num -= pair.first;     // Subtract its value from our number
            }
            
            // 4. Optimization: If the number hits 0, we are done
            if (num == 0) break;
        }
        return roman;
    }
};