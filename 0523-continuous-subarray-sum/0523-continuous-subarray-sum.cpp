class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        map<int,int> mp;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            if(sum%k==0 && i>0) return true;
            
            if(mp.count(sum%k) && (i-mp[sum%k])>=2) return true;
            
            if(mp.count(sum%k)==0) mp[sum%k] = i;
        }
        return false;
    }
};