class Solution {
public:
    void solve(int i, int j, int n, int m, int init_color, int color, vector<vector<bool>>& vis, vector<vector<int>>& image) {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]==color || vis[i][j] || image[i][j]!=init_color) {
            return;
        }

        vis[i][j] = true;
        image[i][j] = color;
        solve(i+1, j, n, m, init_color, color, vis, image);
        solve(i-1, j, n, m, init_color, color, vis, image);
        solve(i, j-1, n, m, init_color, color, vis, image);
        solve(i, j+1, n, m, init_color, color, vis, image);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        int init_color = image[sr][sc];
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        solve(sr, sc, n, m, init_color, color, vis, image);
        return image;
    }
};