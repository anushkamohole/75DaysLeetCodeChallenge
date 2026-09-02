class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        // 1. DFS from all border 'O's to mark them as safe ('T')
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0, m, n);
            if (board[i][n-1] == 'O') dfs(board, i, n-1, m, n);
        }
        
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j, m, n);
            if (board[m-1][j] == 'O') dfs(board, m-1, j, m, n);
        }
        
        // 2. Flip surrounded 'O's to 'X' and safe 'T's back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Captured
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // Safe
                }
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        // Base case: out of bounds or not an 'O'
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        
        // Mark as safe
        board[i][j] = 'T';
        
        // Traverse all 4 directions
        dfs(board, i + 1, j, m, n);
        dfs(board, i - 1, j, m, n);
        dfs(board, i, j + 1, m, n);
        dfs(board, i, j - 1, m, n);
    }
};