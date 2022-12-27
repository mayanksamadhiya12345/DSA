class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n = rocks.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(capacity[i]-rocks[i]);
        }
        
        // 1,1,0,1
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(v[i]!=0 && v[i]<=additionalRocks)
            {
                additionalRocks = additionalRocks-v[i];
                v[i] = 0;
                if(additionalRocks<=0) break;
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0) cnt++;
        }
        return cnt;
    }
};