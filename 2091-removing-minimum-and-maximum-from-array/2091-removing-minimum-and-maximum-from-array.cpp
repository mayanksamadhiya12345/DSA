class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        cout<<mn_idx<<" "<<mx_idx;

        int left = min(mn_idx, mx_idx);
        int right = max(mn_idx, mx_idx);

        int front = right+1;
        int back = n-left;
        int mid = (left+1+n-right);

        return min({front, back, mid});
    }
};
// 5, 1