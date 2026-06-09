class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i<0 || j<0) return 1e9;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int left = grid[i][j] + solve(i, j-1, grid, dp);
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        return dp[i][j] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0][0] = grid[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) continue;
                
                int left = INT_MAX;
                if(j>0) left = grid[i][j]+dp[i][j-1];
                int up = INT_MAX;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                dp[i][j] = min(left, up);
            }
        }
        return dp[n-1][m-1];
    }
};