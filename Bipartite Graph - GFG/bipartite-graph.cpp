//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int node,vector<int>& color,vector<int> adj[])
    {
        color[node] = 0;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            
            for(auto it : adj[nod])
            {
                if(color[it]==-1)
                {
                    color[it] = 1-color[nod];
                    q.push(it);
                }
                else if(color[it]==color[nod])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[])
	{
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!check(i,color,adj))
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends