class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> vt;
        
        for(int i=0;i<n;i++)
        {
            int a = nums[i];
            int b = -a;
            
            int st = i+1;
            int en = n-1;
            while(st<en)
            {
                int sum=nums[st]+nums[en];
                
                if(sum==b)
                {
                    vt.push_back({nums[i],nums[st],nums[en]});
                    while(st+1<n && nums[st]==nums[st+1]) st++;
                    while(en>0 && nums[en]==nums[en-1]) en--;
                    st++;
                    en--;
                }
                else if(sum>b)
                {
                    en--;
                }
                else
                {
                    st++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return vt;
    }
};