class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) 
    {
        // this questions is just like merge intervels
        sort(nums.begin(),nums.end());
        int last_point = nums[0][1];
        int count = 1;
        
        for(auto &it : nums)
        {
            // no overlaping
            if(it[0] > last_point)
            {
                // burst it
                // cout<<it[0]<<" "<<it[1]<<endl;
                count++;
                last_point=it[1];             // updated last point
            }
            else
            {
                last_point = min(last_point,it[1]);
            }
        }
        
        return count;
    }
};