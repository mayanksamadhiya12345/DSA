class Solution {
public:
    bool isValid(vector<int>& a, vector<int>& b)
    {
        if(a[0]==b[0] || a[1] == b[1]) return true;
        return false;
    }
    void dfs(int i, vector<bool>& vis, int n, vector<vector<int>>& stones)
    {
        vis[i] = true;
        for(int idx=0;idx<n;idx++)
        {
            if(vis[idx] == true) continue;
            if(isValid(stones[i], stones[idx])) dfs(idx, vis, n, stones);
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n, false);
        int count=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            dfs(i, vis, n, stones);
            count++;
        }

        return n-count;
    }
};