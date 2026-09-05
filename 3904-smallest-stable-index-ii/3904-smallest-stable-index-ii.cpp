class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        vector<int> left(n), right(n);
        int mn=INT_MAX, mx=INT_MIN;

        for(int i=0;i<n;i++) {
            mx = max(mx, nums[i]);
            left[i] = mx;

            mn = min(mn, nums[n-i-1]);
            right[n-i-1] = mn;
        }

        for(int i=0;i<n;i++) {
            if(left[i]-right[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};