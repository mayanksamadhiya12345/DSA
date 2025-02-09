class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0, {i, j}});
                }
            }
        }

        int step = 0;
        while(!q.empty())
        {
            int time = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();

            step = max(step, time);

            int dr[4] = {-1,0,+1,0};
            int dc[4] = {0,+1,0,-1};

            for(int k=0;k<4;k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                {
                    q.push({time+1, {nr, nc}});
                    grid[nr][nc] = 3;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return step;
    }
};