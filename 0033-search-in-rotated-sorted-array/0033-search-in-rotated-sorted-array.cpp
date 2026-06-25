class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0, right=n-1;

        while(left<right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;

            // left part is sorted
            if(nums[right]<nums[mid]) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return nums[0]==target ? 0 : -1;
    }
};