class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> prefixGcd;
        long long ans = 0;

        long long n = nums.size();
        int mx = 0;
        for(long long i=0;i<n;i++) {
            mx = max(mx, nums[i]);
            int curr_gcd = __gcd(mx, nums[i]);
            prefixGcd.push_back(curr_gcd);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int i=0, j=n-1;
        while(i<j) {
            int curr_gcd = __gcd(prefixGcd[i++], prefixGcd[j--]);
            ans +=  curr_gcd;
        } 
        return ans;
    }
};