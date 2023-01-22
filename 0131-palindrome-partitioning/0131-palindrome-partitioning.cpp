class Solution {
public:
    bool isPalin(int i,int j,string& s)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void find(int i,int n,string& s,vector<string>& ds,vector<vector<string>>& ans)
    {
        if(i==n) ans.push_back(ds);
        
        for(int idx=i;idx<n;idx++)
        {
            if(isPalin(i,idx,s))
            {
                ds.push_back(s.substr(i,idx-i+1));
                find(idx+1,n,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();
        find(0,n,s,ds,ans);
        return ans;
    }
};