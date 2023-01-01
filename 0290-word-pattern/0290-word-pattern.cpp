class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        // just need to map 
        // pattern to string 
        // string to pattern
        
        vector<string> pat;
        string t="";
        for(char c : s)
        {
            if(c==' ')
            {
                pat.push_back(t);
                t="";
            }
            else
            {
                t+=c;
            }
        }
        pat.push_back(t);
        for(auto it : pat) cout<<it<<" ";
        
        if(pat.size() < pattern.size()) return false;
        
        // pattern to string
        map<char,string> mp1;
        int pos=0;

        for(auto c : pattern)
        {
            if(mp1.find(c) == mp1.end())
            {
                mp1[c]=pat[pos];
            }
            else
            {
                if(mp1[c] != pat[pos])
                    return false;
            }
            pos++;
        }
        
        
        // string to pattern 
        map<string,char> mp2;
        pos=0;
        
        for(auto str : pat)
        {
            if(mp2.find(str) == mp2.end())
            {
                mp2[str]=pattern[pos];
            }
            else
            {
                if(mp2[str] != pattern[pos])
                    return false;
            }
            pos++;
        }
        
        return true;
    }
};