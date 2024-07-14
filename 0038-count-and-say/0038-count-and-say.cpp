class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string ans = "11";

        for(int i=3;i<=n;i++)
        {
            string curr = "";
            ans += "*";
            int cnt = 1;
            for(int j=1;j<ans.length();j++)
            {
                if(ans[j] == ans[j-1]) 
                    cnt++;
                else
                {
                    curr += to_string(cnt);
                    curr += ans[j-1];
                    cnt = 1;
                }
            }
            ans = curr;
        }

        return ans;
    }
};

