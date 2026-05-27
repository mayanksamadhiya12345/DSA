class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    q.push({{i, j}, 0});
                    mat[i][j]=2;
                }
            }
        }

        vector<vector<int>> ans(n, vector<int> (m, 0));
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();

            ans[r][c] = step;

            int delr[4] = {-1, 0, 1, 0};
            int delc[4] = {0, -1, 0, 1};
            for(int i=0;i<4;i++) {
                int nr = r+delr[i];
                int nc = c+delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]!=2) {
                    q.push({{nr, nc}, step+1});
                    mat[nr][nc]=2;
                }
            }
        }
        return ans;
    }
};