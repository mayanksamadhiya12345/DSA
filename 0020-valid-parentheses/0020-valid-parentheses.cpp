class Solution {
public:
    bool isValid(string s) 
    {
        int n = s.length();
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                int t = st.top();

                if(s[i] == ')')
                {
                    if(t != '(') return false;
                    else st.pop();
                }
                else if(s[i] == '}')
                {
                    if(t != '{') return false;
                    else st.pop();
                }
                else if(s[i] == ']')
                {
                    if(t != '[') return false;
                    else st.pop();
                }
            }
        }

        if(st.empty()) return true;
        return false;
    }
};