class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st(word.begin(), word.end());
        map<char, int> mp;
        for(auto&it : st) {
            if(it>='a' && it<='z')
                mp[it]++;
            else if(it>='A' && it<='Z')
                mp[it+32]++;
        }

        int count=0;
        for(auto&it : mp) {
            if(it.second>1) {
                cout<<it.first<<" "<<it.second<<endl;
                count++;
            }
        }

        return count;
    }
};