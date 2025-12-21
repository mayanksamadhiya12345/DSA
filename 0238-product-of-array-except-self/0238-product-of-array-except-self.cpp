class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int cnt=0;
        int total=1;
        int idx=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) {
                idx=i;
                cnt++;
                if(cnt==2) return ans;
                continue;
            }

            total*=nums[i];
        }

        if(cnt==1)
        {
            ans[idx] = total;
            return ans;
        }

        for(int i=0;i<n;i++)
        {
            ans[i] = total/nums[i];
        }
        return ans;
    }
};