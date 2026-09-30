class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;
        for (int c=0; c<seq.length(); c++){
            if(seq[c] == '('){
                ans.push_back(depth % 2);
                depth += 1;
            }
            else{
                depth -= 1;
                ans.push_back(depth % 2);
        }
        }
            
        return ans;
    }
};