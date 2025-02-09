class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        long long n = nums.size();
        long long total = (long long) n*(n-1)/2;
        map<long long,long long> mp;
        long long good = 0;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]-i]++;

            if(mp[nums[i]-i] > 1)
            {
                good += (mp[nums[i]-i]-1);
            }
        }
        // for(auto&it : mp)
        // {
        //     int curr = it.second;
        //     if(curr > 1)
        //     {
        //         good += (long long) curr*(curr-1)/2;
        //     }
        // }
        cout<<good;
        return total-good;
    }
};