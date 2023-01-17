class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int count_one=0,count_flip=0;
        
        for(auto it : s)
        {
            if(it=='1') count_one++;
            else
            {
                count_flip++;
                count_flip = min(count_flip,count_one);
            }
        }
        return count_flip;
    }
};