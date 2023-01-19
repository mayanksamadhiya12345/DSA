class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        vector<int> counts(k,0);
        int sum=0;
        for(int a:nums)
        {
            sum += (a%k + k)%k;
            counts[sum%k]++;
        }
        int res=counts[0];
        for(int x:counts)
        {
            res+=(x*(x-1))/2;
        }
        return res;
    }
};