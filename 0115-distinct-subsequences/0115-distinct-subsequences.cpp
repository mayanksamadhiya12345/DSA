class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
        if(i<0 && j>=0) return 0;
        if(j<0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) {
            return dp[i][j] = solve(i-1, j-1, s1, s2, dp) + solve(i-1, j, s1, s2, dp);
        }

        return dp[i][j] = solve(i-1, j, s1, s2, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};