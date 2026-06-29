class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++) {
            string str="";
            for(int j=i;j<n;j++) {
                str += word[j];
                mp[str]++;
            }
        }

        int cnt=0;
        for(auto&it : patterns) {
            if(mp.find(it) != mp.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};