class Solution {
public:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<int>& check,vector<int> adj[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                // if we found cycle anywhere it means it not can not be safe node at all
                if(dfs(it,vis,pathvis,check,adj))
                {
                    return true;
                }
            }
            else if(pathvis[it]==1)           // cycle found {already visited both}
            {
                return true;
            }
        }
        
        check[node] = 1;                // if we don't find any cycle for node then mark it as safe node
        pathvis[node] = 0;              // make this not visited
        return false;                   // no cycle
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        vector<int> adj[V];
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
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