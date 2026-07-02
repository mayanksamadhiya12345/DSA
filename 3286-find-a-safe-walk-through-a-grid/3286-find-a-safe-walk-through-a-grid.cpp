class Solution {
public:
    bool solve(int i, int j, int n, int m, vector<vector<int>>& grid, int health, vector<vector<bool>>& vis) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || health<1) return false;

        if(i==n-1 && j==m-1) {
            if(health-grid[i][j] >= 1) return true;
            return false;
        }

        vis[i][j]=true;
        health -= grid[i][j];
        bool left = solve(i, j-1, n, m, grid, health, vis);
        bool right = solve(i, j+1, n, m, grid, health, vis);
        bool up = solve(i-1, j, n, m, grid, health, vis);
        bool down = solve(i+1, j, n, m, grid, health, vis);
        vis[i][j]=false;

        return left || right || up || down;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int,int>>> q;

    int startHealth = health - grid[0][0];
    if(startHealth < 1) return false;

    vector<vector<int>> best(n, vector<int>(m, -1));
    best[0][0] = startHealth;
    q.push({startHealth, {0,0}});

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while(!q.empty()) {
        int hel = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x == n-1 && y == m-1 && hel >= 1) return true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                int newHealth = hel - grid[nx][ny];
                if(newHealth >= 1 && newHealth > best[nx][ny]) {
                    best[nx][ny] = newHealth;
                    q.push({newHealth, {nx, ny}});
                }
            }
        }
    }
    return false;
}
};