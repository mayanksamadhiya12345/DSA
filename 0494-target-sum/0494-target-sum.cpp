class Solution {
public:
    int solve(int i, int n,vector<int>& nums, int target, vector<vector<int>>& dp, int offset)
    {
        if(target < -offset || target > offset) return 0;
        if(i==n) 
        {
            return target==0?1:0;
        }
        if(dp[i][target+offset]!=-1) return dp[i][target+offset];

        int take1 = solve(i+1, n, nums, target-nums[i], dp, offset);
        int take2 = solve(i+1, n, nums, target+nums[i], dp, offset);
        return dp[i][target+offset] = take1+take2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0, n=nums.size();
        for(auto&it:nums) sum+=it;
        int offset = sum;
        vector<vector<int>> dp(n, vector<int> (2*sum+1, -1));
        return solve(0, n, nums, target, dp, offset);
    }
};