class Solution {
public:
    void solve(int i, int j, int n, int m, vector<vector<char>>& grid) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != '1') return;
        grid[i][j]='2';
        solve(i-1, j, n, m, grid);
        solve(i+1, j, n, m, grid);
        solve(i, j-1, n, m, grid);
        solve(i, j+1, n, m, grid);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1') {
                    solve(i, j, n, m, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};