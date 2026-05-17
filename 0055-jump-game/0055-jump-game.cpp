class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxJump = 0;
        for(int i=0;i<n;i++) {
            if(i>mxJump) return false;
            else mxJump = max(mxJump, nums[i]+i);
        }
        return true;
    }
};