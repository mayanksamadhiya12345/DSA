class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int reachable = 0;
        for(int i=0;i<n;i++)
        {
            if(i>reachable) return false;                           // if my max jump is lower than i it means i can not reach there
            else reachable = max(reachable,i+nums[i]);              // how max i can jump on a particular index
        }
        return true;
    }
};