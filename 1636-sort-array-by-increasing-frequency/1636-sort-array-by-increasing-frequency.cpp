class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        
        return a.first<b.first;
    }
    
    vector<int> frequencySort(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        
        vector<pair<int,int>> vt;
        for(auto it : mp)
        {
            vt.push_back({it.second,it.first});
        }
        
        sort(vt.begin(),vt.end(),cmp);
        
        vector<int> ans;
        for(int i=0;i<vt.size();i++)
        {
            int freq = vt[i].first;
            int curr = vt[i].second;
            
            for(int i=0;i<freq;i++)
            {
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};