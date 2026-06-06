class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n), right(n), ans(n);
        int leftSum=0, rightSum=0;
        for(int i=0;i<n;i++) {
            // Left Sum
            if(i==0) {
                left[i] = 0;
                leftSum = nums[0];
            }
            else {
                left[i] += leftSum;
                leftSum += nums[i];
            }

            // Right Sum
            if(n-i-1 == n-1) {
                right[n-i-1] = 0;
                rightSum = nums[n-i-1];
            }
            else {
                right[n-i-1] += rightSum;
                rightSum += nums[n-i-1];
            }
        }

        for(int i=0;i<n;i++) {
            ans[i] = abs(left[i]-right[i]);
        }
        return ans;
    }
};