class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        // this question is similar with the LIS just find the dp array and max length for given vector then check how many values are there with same length max
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int mx = 1;
        
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[idx]>nums[prev] && 1+dp[prev]>dp[idx])
                {
                    dp[idx] = 1+dp[prev];
                    cnt[idx] = cnt[prev];
                }
                else if(nums[idx]>nums[prev] && 1+dp[prev]==dp[idx])
                {
                    cnt[idx] += cnt[prev];
                }
            }
            
            if(dp[idx]>mx) mx=dp[idx];
        }
        
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==mx) len += cnt[i];
        }
        
        return len;
    }
};