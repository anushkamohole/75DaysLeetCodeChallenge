class Solution {
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