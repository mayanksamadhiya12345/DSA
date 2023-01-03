// s = "165462"
class Solution {
public:
    int minimumPartition(string s, int k) 
    {
        int cnt=1;                                 // took 1 because at last we will take a number that will be greater then k so for counting that 
        long long num=0;
        for(int i=0;i<s.length();i++)
        {
            int digit = s[i]-'0';
            if(digit > k) return -1;
            
            num = num*10 + digit;
            
            if(num>k)
            {
                cnt++;
                num = s[i]-'0';
            }
            
        }
        
        return cnt;
    }
};