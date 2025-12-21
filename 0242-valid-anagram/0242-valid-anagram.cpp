class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach 1
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};