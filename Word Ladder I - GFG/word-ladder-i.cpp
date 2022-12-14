//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) 
    {
        queue<pair<string,int>> q;                     // word , no. of steps to reach this word
        q.push({startWord,1});
        
        // storing all the wordlist strings into the set, so we easily check and erase a word in less time
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        // check startWord is in the set or not is it is remove it from the set as we have taken that word
        if(s.count(startWord)) s.erase(startWord);
        
        // BFS
        while(!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            // check current word is our targetWord or not
            if(word == targetWord) return step;
            
            // try to change each char of curr word and check in wordList set
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                // try out all possible char from a to z
                for(char ch='a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(s.count(word)) 
                    {
                        q.push({word,step+1});
                        s.erase(word);
                    }
                }
                
                word[i] = original;                                    // after whole iterration change it to their original word
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends