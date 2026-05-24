class Solution {
public:
    int solve(int i, vector<int>& arr, int d, vector<int>& dp) {
        if(dp[i]!=-1) return dp[i];
        int ans = 1;
        int n = arr.size();

        // move right
        for(int idx=i+1;idx<=min(n-1, i+d);idx++) {
            if(arr[idx]>=arr[i]) break;

            ans = max(ans, 1+solve(idx, arr, d, dp));
        }

        // move left
        for(int idx=i-1;idx>=max(0, i-d);idx--) {
            if(arr[idx]>=arr[i]) break;

            ans = max(ans, 1+solve(idx, arr, d, dp));
        }

        return dp[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;
        for(int i=0;i<n;i++) {
            ans = max(ans, solve(i, arr, d, dp));
        }
        return ans;
    }
};