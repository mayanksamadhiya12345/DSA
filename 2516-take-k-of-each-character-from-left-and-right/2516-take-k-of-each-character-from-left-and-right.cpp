class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n=s.length();
        unordered_map<char,int> mp;
        for(auto &it : s) mp[it]++;
        
        if(mp['a']<k || mp['b']<k || mp['c']<k) return -1;
        
        int ans = n;
        int i=n-1,j=n-1;
        
        while(i>=0)
        {
            mp[s[i]]--;
            while(mp['a']<k || mp['b']<k || mp['c']<k)
            {
                mp[s[j]]++;
                j--;
            }
            
            ans = min(ans,i+n-1-j);
            i--;
        }
        return ans;
    }
};