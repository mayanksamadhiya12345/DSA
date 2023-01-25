class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int mx = 0;
        int cnt=0;
        for(auto it : nums)
        {
            if(it==1)
            {
                cnt++;
                mx=max(mx,cnt);
            }
            else
            {
                cnt=0;
            }
        }
        return mx;
    }
};