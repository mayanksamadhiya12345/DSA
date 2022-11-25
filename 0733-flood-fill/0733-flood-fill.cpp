class Solution {
public:
    void dfs(int i,int j,int n,int m,int initial_color,int color,vector<vector<bool>>& vis,vector<vector<int>>& image)
    {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=initial_color || vis[i][j])
            return;
        
        vis[i][j] = true;
        image[i][j] = color;
        dfs(i+1,j,n,m,initial_color,color,vis,image);
        dfs(i-1,j,n,m,initial_color,color,vis,image);
        dfs(i,j-1,n,m,initial_color,color,vis,image);
        dfs(i,j+1,n,m,initial_color,color,vis,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        int initial_color = image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        dfs(sr,sc,n,m,initial_color,color,vis,image);
        return image;
    }
};