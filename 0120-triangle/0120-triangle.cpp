class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(i==n || j==n) return 1e9;
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int down = grid[i][j] + solve(i+1, j, n, grid, dp);
        int down_ri = grid[i][j] + solve(i+1, j+1, n, grid, dp);

        return dp[i][j] = min(down, down_ri);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int j=0;j<n;j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int down_ri = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, down_ri);
            }
        }
        return dp[0][0];
    }
};