class Solution {
public:
    void solve(int i,int n,int tar,vector<int>& nums,vector<int>&ds,vector<vector<int>>& ans)
    {
        if(tar==0) ans.push_back(ds);
        if(i>=n) return;

        for(int idx=i;idx<n;idx++)
        {
            if(idx!=i && nums[idx]==nums[idx-1]) continue;
            if(nums[idx] > tar) break;

            ds.push_back(nums[idx]);
            solve(idx+1,n,tar-nums[idx],nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) 
    {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0,n,tar,nums,ds,ans);
        return ans;
    }
};