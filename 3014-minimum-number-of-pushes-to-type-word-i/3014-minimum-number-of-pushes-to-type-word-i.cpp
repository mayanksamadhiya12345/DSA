class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0, cnt1=0, cnt2=1;
        for(int i=0;i<n;i++) {
            ans += (i/8)+1;
        }

        return ans;
    }
};