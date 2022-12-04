class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        // mark vis nodes true
        vector<bool> vis(n+1,false);
        
        queue<int> q;
        q.push(1);
        vis[1] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(!vis[it.first])
                {
                    vis[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<roads.size();i++)
        {
            if(vis[roads[i][0]] && vis[roads[i][1]])
            {
                ans = min(ans,roads[i][2]);
            }
        }
        
        return ans;
    }
};