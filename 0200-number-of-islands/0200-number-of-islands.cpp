class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1')
            return;
        
        grid[i][j] = '2';
        
        dfs(i-1,j,n,m,grid);
        dfs(i+1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i,j+1,n,m,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        
        return cnt;
    }
};