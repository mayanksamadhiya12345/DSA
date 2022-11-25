class Solution {
public:
    void dfs(int i,int j,int n,int m,int initial_color,int color,vector<vector<int>>& image)
    {
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=initial_color || color==image[i][j])
            return;
        
        image[i][j] = color;           // assign new color for curr cell
         
        dfs(i+1,j,n,m,initial_color,color,image);   // bottom
        dfs(i-1,j,n,m,initial_color,color,image);   // top
        dfs(i,j-1,n,m,initial_color,color,image);   // left
        dfs(i,j+1,n,m,initial_color,color,image);   // right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        int initial_color = image[sr][sc];
        
        dfs(sr,sc,n,m,initial_color,color,image);
        return image;
    }
};