class Solution {
public:
    int solve(int src,int dst,int k,int n,vector<vector<int>> adj[])
    {
        queue<vector<int>> q;
        q.push({src,0,0});
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        
        while(!q.empty())
        {
            int node = q.front()[0];
            int cost = q.front()[1];
            int stop = q.front()[2];
            q.pop();
            
            if(stop>k) continue;
            
            for(auto &it : adj[node])
            {
                int nexNode = it[0];
                int nexWeight = it[1];
                
                if(cost +  nexWeight < dis[nexNode])
                {
                    dis[nexNode] = cost + nexWeight;
                    q.push({nexNode, dis[nexNode],stop+1});
                }
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        else return dis[dst];
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        // Directed Graph
        vector<vector<int>> adj[n];
        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        int ans = solve(src,dst,k,n,adj);
        return ans;
    }
};