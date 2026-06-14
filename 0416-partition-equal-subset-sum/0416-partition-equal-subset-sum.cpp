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
        // vector<vector<int>> dp(n, vector<int> (tar+1, -1));
        vector<vector<int>> dp(n, vector<int> (tar+1, 0));
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(nums[0]<=tar) dp[0][nums[0]] = true;

        for(int i=1;i<n;i++) {
            for(int t=1;t<=tar;t++) {
                int take=false;
                if(nums[i]<=t) {
                    take = dp[i-1][t-nums[i]]; 
                }

                int not_take = dp[i-1][t];
                dp[i][t] = take || not_take;
            }
        }
        return dp[n-1][tar];
    }
};