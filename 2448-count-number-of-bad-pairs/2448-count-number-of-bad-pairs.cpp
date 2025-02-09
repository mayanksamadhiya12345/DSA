class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        long long n = nums.size();
        long long total = (long long) n*(n-1)/2;
        map<long long,long long> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]-i]++;
        }

        long long good = 0;
        for(auto&it : mp)
        {
            int curr = it.second;
            if(curr > 1)
            {
                good += (long long) curr*(curr-1)/2;
            }
        }
        return total-good;
    }
};