class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=2;i<nums.size();i++) {
            int curr = nums[i-2] + nums[i-1];
            if(curr > nums[i]) {
                ans = max(ans, curr+nums[i]);
            }
        }
        return ans;
    }
};

// 1 1 2 10
// 1 2 2