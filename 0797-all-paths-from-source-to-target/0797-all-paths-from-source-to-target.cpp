class Solution {
public:
    void path(int src,int tar,vector<int> adj[],vector<int>& temp,vector<vector<int>>& ans)
    {
        temp.push_back(src);
        if(src==tar)
        {
            ans.push_back(temp);
            return;
        }
        
        for(auto it : adj[src])
        {
            path(it,tar,adj,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>> ans;
        vector<int> temp;
        path(0,n-1,adj,temp,ans);
        return ans;
    }
};