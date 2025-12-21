class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int curr_cnt=0;
        int curr_val=0;
        int mx_cnt=0;

        for(auto&it : st)
        {
            if(!st.count(it-1))
            {
                curr_cnt=1;
                curr_val=it;
                while(st.count(curr_val+1))
                {
                    curr_cnt++;
                    curr_val++;
                }
                mx_cnt=max(mx_cnt, curr_cnt);
            }
        }
        return mx_cnt;
    }
};