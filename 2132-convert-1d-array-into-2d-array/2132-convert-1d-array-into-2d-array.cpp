class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        if(m*n != s) return {};

        vector<vector<int>> nums;

        vector<int> temp;
        for(int i=0;i<s;i++)
        {
            temp.push_back(original[i]);
            if((i+1)%n == 0)
            {
                nums.push_back(temp);
                temp.erase(temp.begin(), temp.end());
            }
        }
        return nums;
    }
};