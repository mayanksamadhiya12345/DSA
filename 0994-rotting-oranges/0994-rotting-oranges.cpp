class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();                          // row
        int m = grid[0].size();                       // col
        
        queue<pair<pair<int,int>,int>> q;                         // {{row,col},time}
        vector<vector<int>> vis(n,vector<int> (m,0));             // visited array
        
        
        // push all the rotten oranges into the queue in form of {{row,col},time}   {time==0}
        // and mark that (row,col) visited
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int ans=0;
        while(!q.empty())
        {
            int r = q.front().first.first;                 // extracting row
            int c = q.front().first.second;                // extracting col
            int t = q.front().second;                      // extracting time
            q.pop();
            
            ans = max(ans,t);                              // each time store the max
            
            // start vis negihoubring
            // possible direction for any particular cell (left(0,-1),right(0,+1),up(-1,0),down(+1,0))
            int delr[] = {0,-1,0,+1};
            int delc[] = {-1,0,+1,0};
            
            for(int i=0;i<4;i++)
            {
                // possible neighbour for current cell
                int nrow = r+delr[i]; 
                int ncol = c+delc[i];
                
                // check boudary, fresh orange, and make sure this is not visited
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2)
                {
                    q.push({{nrow,ncol},t+1});                        // push curr row,col with time+1
                    vis[nrow][ncol] = 2;                              // mark as visited
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // if any cell having fresh orange that is not visited then return -1
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};