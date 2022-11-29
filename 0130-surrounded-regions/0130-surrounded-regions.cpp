class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<bool>>& vis,vector<vector<char>>& board)
    {
        if(i<0 or i>=n or j<0 or j>=m or board[i][j]!='O' or vis[i][j]==true)
            return;
        
        vis[i][j]=true;
        
        dfs(i+1,j,n,m,vis,board);
        dfs(i-1,j,n,m,vis,board);
        dfs(i,j+1,n,m,vis,board);
        dfs(i,j-1,n,m,vis,board);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if it is boundary element
                if(i==0 or j==0 or i==n-1 or j==m-1)
                {
                    if(vis[i][j]==false && board[i][j]=='O')
                    {
                        dfs(i,j,n,m,vis,board);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==true)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};