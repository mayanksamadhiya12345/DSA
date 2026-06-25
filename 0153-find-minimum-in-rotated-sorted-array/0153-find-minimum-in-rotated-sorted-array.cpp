class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;

        while(left<right) {
            int mid = (left+right)/2;

            // left part is sorted
            if(nums[right]<nums[mid]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};