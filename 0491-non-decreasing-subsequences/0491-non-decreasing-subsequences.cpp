class Solution {
public:
    void find(int idx,int n,vector<int>& nums,vector<int>& ds,set<vector<int>>& ans)
    {
        // out of bound
        if(idx>=n)
        {
            // check i am having my subsequence length more than 1 or not
            if(ds.size()>=2) ans.insert(ds);
            return;
        }
        
        // if i am having somehitng in my ds so check my curr idx val is greater or equal to prev or not
        // if my ds ius empty then also put curr idx val into it
        if(!ds.size() || ds.back()<=nums[idx])
        {
            ds.push_back(nums[idx]);
            find(idx+1,n,nums,ds,ans);
            ds.pop_back();
        }
        
        // above conditions are not satisfied, skip curr value
        find(idx+1,n,nums,ds,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ds;
        set<vector<int>> ans;                                  // using set because we need unique subsequences
        
        find(0,n,nums,ds,ans);
        return vector(ans.begin(),ans.end());                  // typcasting from set to vector
    }
};