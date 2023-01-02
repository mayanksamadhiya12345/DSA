class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int count_capital = 0;
        for(auto it : word)
        {
            if(it >= 65 && it <= 90) 
                count_capital++;
        }
        
        if(count_capital==0 || count_capital==word.size())
            return true;
        if(count_capital==1 && word[0]>=65 && word[0]<=90)
            return true;
        
        return false;
    }
};