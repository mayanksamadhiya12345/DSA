class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(), mx=1, childIdx=0;
        vector<int> dp(n, 1), parentIdx(n);
        sort(nums.begin(), nums.end());

        for(int curr=0;curr<n;curr++) {
            parentIdx[curr] = curr;
            for(int prev=0;prev<curr;prev++) {
                if(nums[curr]%nums[prev]==0 && 1+dp[prev] > dp[curr]) {
                    dp[curr] = 1+dp[prev];
                    parentIdx[curr] = prev;
                }
            }
            if(mx<dp[curr]) {
                mx = dp[curr];
                childIdx = curr;
            }
        }

        vector<int> ans;
        while(childIdx != parentIdx[childIdx]) {
            ans.push_back(nums[childIdx]);
            childIdx = parentIdx[childIdx];
        }

        ans.push_back(nums[childIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};