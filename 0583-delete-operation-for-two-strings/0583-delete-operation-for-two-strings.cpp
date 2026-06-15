class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int> curr(m+1, 0), prev(m+1, 0);

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1+prev[j-1];
                }
                else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    int minDistance(string word1, string word2) {
        int val = longestCommonSubsequence(word1, word2);
        int n = word1.length() + word2.length();
        cout<<n<<" "<<val;
        return n-2*val;
    }
};