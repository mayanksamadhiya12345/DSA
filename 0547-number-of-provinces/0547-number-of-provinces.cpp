class Solution {
public:
    void solve(int i, vector<bool>& vis, vector<int> adj[]) {
        vis[i]=true;
        for(auto&it:adj[i]) {
            if(!vis[it]) {
                solve(it, vis, adj);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]==1 && i!=j) {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<bool> vis(n+1, false);
        int count=0;
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                count++;
                solve(i, vis, adj);
            }
        }
        return count;
    }
};