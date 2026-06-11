class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.size()!=t.size()){
        return false;
       }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<s.size(); i++){
            if (s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};
/* OPTIMIZED
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Create an inventory for the 26 lowercase English letters
        int count[26] = {0}; 

        // Make one single pass through both strings
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // 
            count[t[i] - 'a']--; // 
        }

        // Check the inventory. If anything is NOT zero, it's not an anagram.
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};*/

