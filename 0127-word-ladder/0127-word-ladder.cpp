class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) return steps;

            int size = word.length();
            for(int i=0;i<size;i++) {
                char org = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    if(words.count(word)) {
                        q.push({word, steps+1});
                        words.erase(word);
                    }
                }
                word[i]=org;
            }
        }
        return 0;
    }
};