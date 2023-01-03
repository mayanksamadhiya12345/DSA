class Solution {
public:
    int minimumPartition(string s, int k) 
    {
        int cnt=0;
        long long num=0;
        for(int i=0;i<s.length();i++)
        {
            int digit = s[i]-'0';
            if(digit > k) return -1;                   // if any time our single digit goes bigger then k return -1, there will no partition possible
            
            num = num*10 + digit;                      // each time compute num
            
            // if our computed num goes bigger then count it as a partition
            if(num>k)
            {
                cnt++;
                num = digit;                        // assign curr digit to num for next calls
             }
            
        }
        
        // if num is still less than k, then count it as a substring
        if(num<=k) cnt++;
        return cnt;
    }
};