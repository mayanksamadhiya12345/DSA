class Solution {
public:
    // Two basic checks are there (one for size and one for char freq and char equality)
    bool closeStrings(string word1, string word2) 
    {
        int n = word1.length();
        int m = word2.length();
        
        if(n!=m) return false;
        
        set<char> s1,s2;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        
        // start counting frequency of each char and put it into the set
        for(int i=0;i<n;i++)
        {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        
        // sort the frequency vector according to their char occurances
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        // if set all values are same and freq of their char also same
        if(s1==s2 && freq1==freq2) return true;
        
        return false;
    }
};