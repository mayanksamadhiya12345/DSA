//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,int n,int m,vector<vector<bool>>& vis,vector<pair<int,int>>& vt,vector<vector<int>>& grid,int r0,int c0)
    {
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c]!=1 || vis[r][c]==true)
        {
            return;
        }
        
        vis[r][c] = true;
        
        vt.push_back({r-r0,c-c0});
        
        dfs(r-1,c,n,m,vis,vt,grid,r0,c0);
        dfs(r+1,c,n,m,vis,vt,grid,r0,c0);
        dfs(r,c-1,n,m,vis,vt,grid,r0,c0);
        dfs(r,c+1,n,m,vis,vt,grid,r0,c0);
    }
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<pair<int,int>> vt;
                if(grid[i][j]==1 && !vis[i][j])
                {
                    dfs(i,j,n,m,vis,vt,grid,i,j);
                    
                    st.insert(vt);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends