class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      //Hash Set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the target word isn't available, a path is impossible
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        // Sequence length starts at 1 (counting the beginWord)
        int level = 1; 
        
        //BFS Loop
        while (!q.empty()) {
            int size = q.size(); // Number of words in the current BFS layer
            
            // Process all words at the current level together
            for (int i = 0; i < size; i++) {
                string currentWord = q.front();
                q.pop();
                
                // We found the shortest path!
                if (currentWord == endWord) return level;
                
                // Generate all possible 1-letter transformations
                for (int j = 0; j < currentWord.length(); j++) {
                    char originalChar = currentWord[j];
                    
                    // Try replacing the character at index j with 'a' through 'z'
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        
                        currentWord[j] = c;
                        
                        // If the mutated word exists in our dictionary
                        if (dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord); // Mark as visited by removing it
                        }
                    }
                    // Backtrack: Restore the original character before moving to the next index
                    currentWord[j] = originalChar;
                }
            }
            // Move to the next depth layer
            level++; 
        }
        
        return 0; // The queue emptied out, meaning no path exists
    }
};