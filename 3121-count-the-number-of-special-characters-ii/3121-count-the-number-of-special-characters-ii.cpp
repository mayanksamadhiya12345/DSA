class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        int n = word.length();

        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c >= 'a' && c <= 'z') {
                if (lower[c - 'a'] == -1 || lower[c - 'a']<i)
                    lower[c - 'a'] = i;
            } else if (c >= 'A' && c <= 'Z') {
                if(upper[c - 'A'] == -1)
                    upper[c - 'A'] = i;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                cout<<i<<endl;
                count++;
            }
        }
        return count;
    }
};
