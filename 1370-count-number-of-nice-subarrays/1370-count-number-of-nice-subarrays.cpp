class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int count = 0;
        
        int i=0,j=0;
        int cnt=0;

        while(j < n)
        {
            if(nums[j] % 2 != 0) 
            {
                k--;
                cnt=0;
            }

            while(k==0)
            {
                if(nums[i] % 2 != 0) k++;
                cnt++;
                i++;
            }

            count += cnt;
            j++;
        }
        return count;
    }
};