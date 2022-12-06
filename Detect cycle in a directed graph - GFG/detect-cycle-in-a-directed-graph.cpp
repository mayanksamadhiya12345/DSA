//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool check(int node,vector<int>& vis,vector<int>& dfsvis,vector<int> adj[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(check(it,vis,dfsvis,adj))
                {
                    return true;
                }
            }
            else if(dfsvis[it])
            {
                return true;
            }
        }
        
        dfsvis[node]=0;
        return false;
    }
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(check(i,vis,dfsvis,adj))
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

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends