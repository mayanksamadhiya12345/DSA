//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        
        // pushing all cells that are having value 1 with step 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    q.push({{i,j},0});                              // position,steps
                    vis[i][j] = true;
                }
            }
        }
        
        
        vector<vector<int>> ans(n,vector<int> (m,0));
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            
            ans[row][col] = step;                              // put the step count for current row col cell
            
            // possible 4 direction
            int delrow[] = {-1,0,+1,0};
            int delcol[] = {0,-1,0,+1};
            
            for(int i=0;i<4;i++)
            {
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = true;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends