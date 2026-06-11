#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int left = 0, right = 0, i = 0;

        while (i < n) {
            // 1. Skip any extra spaces with our read pointer 'i'
            while (i < n && s[i] == ' ') {
                i++;
            }
            
            if (i == n) break; // If we reached the end, stop.

            // 2. If this isn't the very first word, add a single space to separate them
            if (right > 0) {
                s[right++] = ' ';
            }

            // 3. Mark the start of the current word
            left = right;

            // 4. Copy the word characters to their proper place
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // 5. Un-reverse the word we just placed!
            reverse(s.begin() + left, s.begin() + right);
        }

        // Step 6: Chop off the leftover garbage characters at the end of the string
        s.resize(right);

        return s;
    }
};
/*class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.length() - 1;

        while (i >= 0) {
            // 1. Skip any trailing spaces or multiple spaces between words
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            // If we went out of bounds while skipping spaces, we are done
            if (i < 0) {
                break; 
            }

            // 2. Lock 'j' at the end of the word
            int j = i;

            // 3. Move 'i' backward until we find a space (the start of the word)
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            // 4. Extract the trapped word
            // The word starts at i + 1. Its length is j - i.
            string word = s.substr(i + 1, j - i);

            // 5. Append to result (add a space first if result isn't empty)
            if (result.empty()) {
                result = word;
            } else {
                result = result + " " + word;
            }
        }

        return result;
    }
};
*/