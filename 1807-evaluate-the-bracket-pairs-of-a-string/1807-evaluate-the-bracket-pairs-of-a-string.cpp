class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string res = "";
        string key_buf = "";
        bool in_bracket = false;

        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
                key_buf = "";
            } else if (c == ')') {
                in_bracket = false;
                auto it = mp.find(key_buf);
                if (it != mp.end()) {
                    res += it->second;
                } else {
                    res += '?';
                }
            } else if (in_bracket) {
                key_buf += c;
            } else {
                res += c;
            }
        }

        return res;
    }
};