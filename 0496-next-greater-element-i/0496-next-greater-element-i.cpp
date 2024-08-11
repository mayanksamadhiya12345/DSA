class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]] = i;
        }

        vector<int> ans;
        for(int i=0;i<n1;i++)
        {
            int curr = nums1[i];
            int idx = mp[curr];
            // bool flag = false;

            for(int j=idx+1;j<n2;j++)
            {
                // If I'm findign any big value then that will be the part of my answer vector
                if(nums2[j] > curr)
                {
                    ans.push_back(nums2[j]);
                    // after taking the big value there is no mean to procedd further so just break the loop by saying I found one big value
                    // flag = true;
                    break;
                }

                // if you reached to the last index without findign any big value so insert -1
                if(j==n2-1) ans.push_back(-1);
            }
            if(idx == n2-1) ans.push_back(-1);
            // if we have not found any big value in that case -1 should be included
            // if(flag == false) ans.push_back(-1);
        }
        return ans;
    }
};

// 