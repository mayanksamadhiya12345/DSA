class Solution {
public:
    bool solve(vector<int>& arr, int n, int start, vector<bool>& vis, vector<int>& dp) {
        if(start<0 || start>=n || vis[start])
            return false;

        if(dp[start]!=-1) return dp[start];

        vis[start] = true;
        if(arr[start]==0) return true;

        return dp[start] = solve(arr, n, start-arr[start], vis, dp) || solve(arr, n, start+arr[start], vis, dp);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n, false);
        vector<int> dp(n, -1);
        return solve(arr, n, start, vis, dp);
    }
};