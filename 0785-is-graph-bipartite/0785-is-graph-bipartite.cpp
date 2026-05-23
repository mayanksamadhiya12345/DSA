class Solution {
public:
    bool checkBip(int node, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = 0;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int Node = q.front();
            q.pop();

            for(auto&it : graph[Node]) {
                if(color[it] == -1) {
                    color[it] = 1-color[Node];
                    q.push(it);
                }
                else if(color[it] == color[Node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++) {
            if(color[i] == -1) {
                if(!checkBip(i, color, graph)) return false;
            }
        }
        return true;
    }
};