class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach 1
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;

        // Approach 2
        map<int,int> mp1, mp2;
        for(auto&it : s) mp1[it]++;
        for(auto&it : t) mp2[it]++;

        for(auto&it : t) {
            if(mp1[it] == 0) return false;
            mp1[it]--;
        }

        for(auto&it : s) {
            if(mp2[it] == 0) return false;
            mp2[it]--;
        }
        return true;
    }
};