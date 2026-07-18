class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char, int> mp;
        int maxLen=0;

        for(int right = 0; right < s.size(); right++) {

        while(mp[s[right]] > 0) {
            mp[s[left]]--;
            left++;
        }

        mp[s[right]]++;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;

    }
};
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use a vector of size 128 (for standard ASCII) initialized to -1
        vector<int> lastSeen(128, -1);
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];

            // If we've seen this character and it's inside our current window
            if (lastSeen[currentChar] >= left) {
                // Jump the left pointer directly past the duplicate
                left = lastSeen[currentChar] + 1;
            }

            // Update the last seen index of the current character
            lastSeen[currentChar] = right;
            
            // Calculate max length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};*/