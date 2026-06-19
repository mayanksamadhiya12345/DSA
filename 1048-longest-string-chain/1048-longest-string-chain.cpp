class Solution {
public:
    bool check(string& s1, string& s2) {
        if(s1.length()+1 != s2.length()) return false;
        
        int n = s1.length(), m=s2.length();
        int i=0, j=0;
        while(i<n && j<m) {
            if(s1[i]==s2[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return i==n;
    }
    static bool comp(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int mx=0;
        sort(words.begin(), words.end(), comp);
        for(int curr=0;curr<n;curr++) {
            for(int prev=0;prev<curr;prev++) {
                if(check(words[prev], words[curr]) && 1+dp[prev] >= dp[curr]) {
                    dp[curr] = 1+dp[prev];
                }
            }
            mx = max(mx, dp[curr]);
        }
        return mx;
    }
};