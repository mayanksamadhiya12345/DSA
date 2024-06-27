class Solution {
public:
    void solve(int i,int j,int n,int m,int init_color,int color,vector<vector<int>>& image)
    {
        if(i<0 || j<0 || i>=n || j>=m || color==image[i][j] || init_color!=image[i][j]) return;

        image[i][j] = color;

        solve(i-1,j,n,m,init_color,color,image);
        solve(i+1,j,n,m,init_color,color,image);
        solve(i,j-1,n,m,init_color,color,image);
        solve(i,j+1,n,m,init_color,color,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int init_color = image[sr][sc];
        solve(sr, sc, n, m, init_color, color, image);
        return image;
    }
};