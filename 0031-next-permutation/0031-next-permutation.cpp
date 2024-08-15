class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int l,k;
        int n=nums.size();
        for(k=n-2;k>=0;k--)
        {
            if(nums[k+1] > nums[k]) break;
        }

        if(k < 0) return reverse(nums.begin(), nums.end());

        for(l=n-1;l>k;l--)
        {
            if(nums[l] > nums[k])
            {
                break;
            }
        }
        swap(nums[l], nums[k]);
        reverse(nums.begin()+k+1, nums.end());
    }
};