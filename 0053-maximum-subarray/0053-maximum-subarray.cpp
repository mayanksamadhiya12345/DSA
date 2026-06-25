class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr=0;
        for(auto&it : nums) {
            curr += it;
            ans = max(ans, curr);
            if(curr<0) {
                curr=0;
            }
        }
        return ans;
    }
};