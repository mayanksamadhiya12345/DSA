class Solution {
public:
    void solve(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& board) {
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j] != 1)
            return;

        vis[i][j] = true;
        solve(i+1, j, n, m, vis, board);
        solve(i-1, j, n, m, vis, board);
        solve(i, j+1, n, m, vis, board);
        solve(i, j-1, n, m, vis, board);
        return;
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 || i==n-1 || j==0 || j==m-1) {
                    solve(i, j, n, m, vis, board);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j] == true) {
                    continue;
                }
                else if(board[i][j]==1) {
                    count++;
                }
            }
        }
        return count;
    }
};