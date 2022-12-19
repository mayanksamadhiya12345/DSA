class Solution {
public:
    bool ifPath(int source,int destination,vector<bool>& vis,vector<int> adj[])
    {
        vis[source]=true;
        cout<<source<<" ";

        for(auto it : adj[source])
        {
            if(!vis[it])
            {
                if(ifPath(it,destination,vis,adj))
                {
                    return true;
                }
            }
        }
        if(source==destination) return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if(source==destination) return true;
        
        // store the graph
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(n,false);
        if(ifPath(source,destination,vis,adj))
        {
            return true;
        }
        return false;
    }
};