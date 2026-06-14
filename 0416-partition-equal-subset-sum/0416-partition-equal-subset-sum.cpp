class Solution {
public:
    bool solve(int i, int tar, vector<int>& nums, vector<vector<int>>& dp) {
        if(i==0) return tar==nums[i];
        if(dp[i][tar]!=-1) return dp[i][tar];

        int take=false;
        if(nums[i]<tar) {
            take = solve(i-1, tar-nums[i], nums, dp);
        }

        int not_take = solve(i-1, tar, nums, dp);
        return dp[i][tar] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target=0;
        for(auto&it : nums) {
            target += it;
        }

        if(target%2!=0) return false;
        int tar = target/2;
        vector<vector<int>> dp(n, vector<int> (tar+1, -1));
        return solve(n-1, target/2, nums, dp);
    }
};