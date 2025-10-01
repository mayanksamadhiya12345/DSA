class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        map<string, int> seqMap;
        seqMap[beginWord] = 1;

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == endWord) 
            {
                break;
            }

            int size = word.length();
            for(int i=0;i<size;i++) {
                char org = word[i];
                for(char ch='a';ch<='z';ch++) {
                    word[i] = ch;
                    if(words.count(word)) {
                        q.push({word, steps+1});
                        seqMap[word] = 1+steps;
                        words.erase(word);
                    }
                }
                word[i]=org;
            }
        }

        vector<vector<string>> ans;
        vector<string> seq;
        if(seqMap.find(endWord) != seqMap.end()) {
            seq.push_back(endWord);
            solve(endWord, beginWord, seqMap, seq, ans);
        }
        return ans;
    }

    void solve(string& src, string& dst, map<string, int>& seqMap, vector<string>& seq, vector<vector<string>>& ans) {
        if(src == dst) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int size = src.length();
        int steps = seqMap[src];
        for(int i=0;i<=size;i++) {
            char org = src[i];
            for(char ch='a';ch<='z';ch++) {
                src[i] = ch;
                if(seqMap.count(src) && 1+seqMap[src] == steps) {
                    seq.push_back(src);
                    solve(src, dst, seqMap, seq, ans);
                    seq.pop_back();
                }
            }
            src[i] = org;
        }
        return;
    }
};