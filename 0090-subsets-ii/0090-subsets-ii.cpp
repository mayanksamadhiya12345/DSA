class Solution {
public:
    void solve(int i,int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans)
    {
        ans.push_back(ds);
        if(i>=n) return;

        for(int idx=i;idx<n;idx++)
        {
            if(idx!=i && nums[idx]==nums[idx-1]) continue;

            ds.push_back(nums[idx]);
            solve(idx+1,n,nums,ds,ans);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0, n, nums, ds, ans);
        return ans;
    }
};