//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool detect(int node,vector<bool>& vis,vector<int> adj[])
    {
        vis[node] = true;
        queue<pair<int,int>> q;           // child,par
        
        q.push({node,-1});
        while(!q.empty())
        {
            int child = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it : adj[child])
            {
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push({it,child});
                }
                else if(par != it)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,vis,adj))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends