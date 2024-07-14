class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int n1 = version1.length();     // extracting length of string version1
        int n2 = version2.length();     // extracting length of string version2
        
        // variables(pointers) used for moving
        int i = 0;
        int j = 0;               
        
        // numbers that generated between any two dots of the strings
        int num1 = 0;
        int num2 = 0;   
        
        // start traversing from string 1 and string 2
        while(i < n1 || j < n2)
        {
            // generating number between dots for string version1
            while(i < n1 && version1[i] != '.')
            {
                num1 = num1*10 + (version1[i] - '0');
                i++;
            }
            
            // generating number between dots for string version2
            while(j < n2 && version2[j] != '.')
            {
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }
            
            // if number1 is greater than number2, from here return 1
            if(num1 > num2)
            {
                return 1;
            }
            
             // if number1 is less than number2, from here return -1
            if(num1 < num2)
            {
                return -1;
            }
            
            // if equal then we have to proceed further
            // again give numbers to zero, as we again generate numbers b/w dots 
            num1 = 0, num2 = 0;
            
            // move both pointers
            i++;
            j++;
        }
        
        // after traversing whole string, if all the versions are equal, that means strings are equal, so return 0 
        return 0;
    }
};