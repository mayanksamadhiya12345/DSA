class Solution {
public:
    void solve(int i,int n,int tar,vector<int>& nums,vector<int>&ds,vector<vector<int>>& ans)
    {
        if(tar == 0) 
        {
            ans.push_back(ds);
            return;
        }
        if(i>=n) return;

        if(nums[i] <= tar)
        {
            ds.push_back(nums[i]);
            solve(i,n,tar-nums[i],nums,ds,ans);
            ds.pop_back();
        }

        solve(i+1, n, tar, nums, ds, ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) 
    {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,n,tar,nums,ds,ans);
        return ans;
    }
};