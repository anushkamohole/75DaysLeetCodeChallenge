class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        
        vector<vector<int>> result(C, vector<int>(R));
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                result[c][r] = matrix[r][c];
            }
        }
        
        return result;
    }
};