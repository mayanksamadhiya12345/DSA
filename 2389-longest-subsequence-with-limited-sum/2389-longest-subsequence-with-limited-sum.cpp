class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        int n = queries.size();
        
        // sort the array, because order will not matter
        sort(nums.begin(), nums.end());
        
        // find the prefix sum
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }
        
        // res[i] will store the answer of each query
        vector<int> res(n);
        
        // solve for each query
        for(int i = 0; i < n; i++)
        {
            // find the upper bound of sum
            int idx = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            res[i] = idx;
        }
        
        return res;
    }
};