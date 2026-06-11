class Solution {
public:
    const int MOD = 1e9+7;

    int solve(int i, vector<int> adj[], vector<bool>& vis) {
        vis[i] = true;
        int mxDepth = 0;
        for(auto& it : adj[i]) {
            if(!vis[it]) {
                mxDepth = max(mxDepth, 1 + solve(it, adj, vis));
            }
        }
        return mxDepth;
    }

    long long localPow(long long base, long long times, int mod) {
        long long res = 1;
        while(times--) {
            res = (res*base)%mod;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int N = 0;
        for(auto& it : edges) {
            N = max(N, max(it[0], it[1]));
        }
        vector<int> adj[N+1];
        for(auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(N+1, false); 
        int depth = solve(1, adj, vis);

        long long val = localPow(2, depth-1, MOD);  // now works fine
        cout << val;
        return (int)val;
    }
};
