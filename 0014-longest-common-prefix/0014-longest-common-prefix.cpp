class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // 1. Sort the array alphabetically
        sort(strs.begin(), strs.end());

        // 2. Grab the most different strings (first and last)
        string first = strs[0];
        string last = strs.back(); // .back() gets the last element in a vector
        
        int i = 0;

        // 3. Compare them character by character until a mismatch or one ends
        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            i++;
        }

        // 4. Return the matched portion from the first string
        return first.substr(0, i);
    }
};