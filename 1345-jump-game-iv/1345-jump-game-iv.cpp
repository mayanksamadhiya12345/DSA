class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        vector<bool> vis(n, false);

        // Val, all_occurred_indices
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++) {
            mp[arr[i]].push_back(i);
        }
    
        // Starting from 1st index
        int jump=0;
        q.push(0);
        vis[0]=true;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int idx = q.front();
                q.pop();

                if(idx==n-1) return jump;

                // i-1
                if(idx-1>=0 && !vis[idx-1]) {
                    q.push(idx-1);
                    vis[idx-1]=true;
                }

                // i+1
                if(idx+1<n && !vis[idx+1]) {
                    q.push(idx+1);
                    vis[idx+1]=true;
                }

                // Indices with same value
                for(auto&it : mp[arr[idx]]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it]=true;
                    }
                }
                mp.erase(arr[idx]);
            }
            jump++;
        }
        return -1;
    }
};