class Solution {
public:
    static const int MOD = 1000000007;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> depth(n + 1, 0), parent(n + 1, 0), visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = 1;
                    depth[nei] = depth[node] + 1;
                    parent[nei] = node;
                    q.push(nei);
                }
            }
        }
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n + 1));
        up[0] = parent;
        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v <= n; v++) {
                up[k][v] = up[k - 1][up[k - 1][v]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++) {
                if ((diff >> k) & 1) {
                    u = up[k][u];
                }
            }

            if (u == v) 
                return u;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return up[0][u];

        };
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = 1LL * pow2[i - 1] * 2 % MOD;
        }

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            int ancestor = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[ancestor];
            ans.push_back(dist ? pow2[dist - 1] : 0);
        }
        return ans;
    }
};