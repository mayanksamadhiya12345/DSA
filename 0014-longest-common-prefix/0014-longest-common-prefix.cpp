class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        string l = arr[0];
        string r = arr[n-1];
        string ans="";
        
        for(int i=0;i<l.size();i++)
        {
            if(l[i]==r[i]) ans += l[i];
            else break;
        }
        return ans;
    }
};