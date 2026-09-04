class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<int> match(s.length(), -1);
        
        for (int i = 0; i < indices.size(); ++i) {
            int idx = indices[i];
            string src = sources[i];
            
            if (idx + src.length() <= s.length() && s.substr(idx, src.length()) == src) {
                match[idx] = i;
            }
        }
        
        string ans = "";
        int ptr = 0;
        while (ptr < s.length()) {
            if (match[ptr] != -1) {
                int i = match[ptr];
                ans += targets[i];
                ptr += sources[i].length();
            } else {
                ans += s[ptr];
                ptr++;
            }
        }
        return ans;
    }
};