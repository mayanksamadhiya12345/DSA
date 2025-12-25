class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> ans(nums);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && nums[i]>nums[j])
                {
                    count++;
                }
            }
            ans[i]=count;
        }
       return ans;     
    }
};