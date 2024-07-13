class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n=s.length();
        if(n==1) return s;

        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
            if(i==n-1) break;

            dp[i][i+1] = (s[i]==s[i+1]);
        }

        for(int i=n-3;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1;
            }
        }

        int mx = INT_MIN;
        string str = "";

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(dp[i][j] && mx<j-i+1)
                {
                    mx = j-i+1;
                    str = s.substr(i,j-i+1);
                }
            }
        }
        return str;
    }
};