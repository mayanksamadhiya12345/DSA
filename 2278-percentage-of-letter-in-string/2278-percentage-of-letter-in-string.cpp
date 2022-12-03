class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int numerator = 0;
        int denominator = s.length();
        
        for(auto it : s)
        {
            if(it==letter) numerator++;
        }
        
        return ((numerator*100)/denominator);
    }
};