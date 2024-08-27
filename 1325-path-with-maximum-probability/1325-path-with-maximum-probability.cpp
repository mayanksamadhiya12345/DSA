class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
       vector<pair<int, double>> adj[n];
       for(int i=0;i<edges.size();i++)
       {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
       }

       vector<double> Prob(n, 0.0);
       Prob[start] = 1.0;
       queue<double> q;
       q.push(start);

       while(!q.empty())
       {
            int curr = q.front();
            q.pop();

            for(auto& it : adj[curr])
            {
                int next = it.first;
                double prob = it.second;

                double nextProb = Prob[curr] * prob;
                if(nextProb > Prob[next])
                {
                    Prob[next] = nextProb;
                    q.push(next);
                }
            }
       }

       return Prob[end];
    }
};