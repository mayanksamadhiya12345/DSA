class Solution {
public:
    bool isPalin(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void solve(int i,int n,string& s,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(i>=n)
        {
            ans.push_back(ds);
            return;
        }

        for(int idx=i;idx<n;idx++)
        {
            if(isPalin(s,i,idx))
            {
                ds.push_back(s.substr(i,idx-i+1));
                solve(idx+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.length();
        solve(0,n,s,ds,ans);
        return ans;
    }
};