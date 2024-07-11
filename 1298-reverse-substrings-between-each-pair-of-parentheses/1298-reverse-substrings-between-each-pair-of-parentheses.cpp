class Solution {
public:
    string reverseParentheses(string s) {
        // create stack to keep track the oprning brackets indexes
        stack<int> st;
        string ans = "";

        int n = s.length();
        int i=0;
        while(i<n)
        {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')')
            {
                int start = st.top() + 1;         // +1 cause, stack is keeping the index of opening brackets and we need to reverse the leteers only
                int en = i;

                reverse(s.begin()+start, s.begin()+en);
                st.pop();
            }

            i++;
        }

        for(auto&it : s)
        {
            if(it!='(' && it!=')') ans += it;
        }

        return ans;
    }
};