//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,int n,int m,vector<vector<int>>& grid)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]!=1)
            return;
        
        grid[r][c] = 2;                 // start marking boundary conneced 1 so we will not count them for not move
         
        dfs(r+1,c,n,m,grid);
        dfs(r-1,c,n,m,grid);
        dfs(r,c+1,n,m,grid);
        dfs(r,c-1,n,m,grid);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // for all boundary values if there is 1 then cover all its connected one (because from there we can move outside)
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(i,j,n,m,grid);
                    }
                }
            }
        }
        
        int not_move = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // count 1 by which we can not move outside (non boundary connected)
                if(grid[i][j]==1)
                {
                    not_move++;
                }
            }
        }
        
        return not_move;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends