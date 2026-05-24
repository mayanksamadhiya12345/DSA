class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.count(beginWord))
            s.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;
            int n = word.length();
            for(int i=0;i<n;i++) {
                char org = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    if(s.count(word)) {
                        q.push({word, step+1});
                        s.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};