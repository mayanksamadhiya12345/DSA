class Solution {
public:
    int solve(int i, int n, string s, set<string>& st, vector<int>& dp)
    {
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];

        int extra = n;
        string curr = "";
        for(int idx=i;idx<n;idx++)
        {
            curr += s[idx];

            int nextExtra = solve(idx+1, n, s, st, dp);
            int currExtra = st.count(curr) ? 0 : curr.size();

            extra = min(extra, nextExtra+currExtra);
        }

        return dp[i] = extra;
    }
    int minExtraChar(string s, vector<string>& d) {
        int n = s.length();
        set<string> st;
        vector<int> dp(n, -1);
        for(auto&it : d) st.insert(it);
        return solve(0, n, s, st, dp);
    }
};