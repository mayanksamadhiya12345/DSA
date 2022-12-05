//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<int>& check,vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                // if we found cycle anywhere it means it not can not be safe node at all
                if(dfs(it,vis,pathvis,check,adj))
                {
                    return true;
                }
            }
            else if(pathvis[it])           // cycle found {already visited both}
            {
                return true;
            }
        }
        
        check[node] = 1;                // if we don't find any cycle for node then mark it as safe node
        pathvis[node] = 0;              // make this not visited
        return false;                   // no cycle
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int> vis(V,0);                        // visited
        vector<int> pathvis(V,0);                    // for keep tracking directed graph
        vector<int> check(V,0);                      // it will store safe as 1
        
        // for each component
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathvis,check,adj);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends