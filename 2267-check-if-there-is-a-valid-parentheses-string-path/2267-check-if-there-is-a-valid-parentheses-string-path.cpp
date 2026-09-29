class Solution {
public:
    int m, n;
    int memo[105][105][205]; 
    
    bool dfs(int r, int c, int balance, vector<vector<char>>& grid) {
        if (r >= m || c >= n) return false;
        
        balance += (grid[r][c] == '(') ? 1 : -1;
        
        if (balance < 0) return false;
        
        if (r == m - 1 && c == n - 1) return balance == 0;
        
        if (memo[r][c][balance] != -1) return memo[r][c][balance];
        
        bool res = dfs(r + 1, c, balance, grid) || dfs(r, c + 1, balance, grid);
        return memo[r][c][balance] = res;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};