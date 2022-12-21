class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        // we can solve problem by using bipartite graph problem
        // how : as we know in bipartite grapg we have exact two colols by which we can color it
        // so here we can think if there are only two colors by which we can color it, so what if we think
        // instead of color, we can exactly store these values in two groups without conflict Right?
        // now question becomes Is given 2d vector biparite (true) or not (false)
        
        // color 0 : set 1
        // color 1 : set 2
        
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);   
            adj[dislikes[i][1]].push_back(dislikes[i][0]);   
        }
        
        vector<int> color(n+1,-1);                 // checking for colors
        
        // for every component
        for(int i=1;i<=n;i++)
        {
            // not colored
            if(color[i]==-1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    // checking for all adjacency nodes
                    for(auto it : adj[node])
                    {
                        // if not colored then color it with oppodite color and push it into the queue
                        if(color[it]==-1)
                        {
                            color[it] = 1-color[node];
                            q.push(it);
                        }
                        // already colored and having same color then return false
                        else if(color[it]==color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};