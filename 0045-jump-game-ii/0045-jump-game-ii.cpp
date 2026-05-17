class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int mxJump=0, jump=0, nextPos=0;
        for(int i=0;i<n;i++) {
            if(mxJump==n) return jump;
            if(i>mxJump) return 0;
            else mxJump = max(mxJump, nums[i]+i);

            if(i==nextPos) {
                jump++;
                nextPos = mxJump;
            }
        }
        return jump-1;
    }
};