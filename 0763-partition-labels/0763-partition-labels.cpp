class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        vector<int> last_idx(26, 0);
        
        //Record the last occurrence 
        for (int i = 0; i < s.length(); ++i) {
            last_idx[s[i] - 'a'] = i;
        }
        
        std::vector<int> result;
        int start = 0;
        int end = 0;
        
        //Find the partitions
        for (int i = 0; i < s.length(); ++i) {
            // The chunk must stretch to at least the last occurrence of the current character
            end = max(end, last_idx[s[i] - 'a']);
            
            // If our current index has reached the furthest required boundary, make a cut
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1; 
            }
        }
        
        return result;
    }
};