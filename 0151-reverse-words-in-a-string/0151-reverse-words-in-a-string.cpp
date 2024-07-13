class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string str = "";

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                str += s[i];
            }
            else if(i!=0 && s[i]==' ')
            {
                str += ' ';
                while(i+1<s.length() && s[i+1]==' ')
                {
                    i++;
                }
            }
        }

        string ans="";
        string tmp="";
        int n2 = str.length();

        for(int i=0;i<n2;i++)
        {
            if(str[i]==' ')
            {
                if(ans=="") ans = tmp;
                else ans = tmp + " " + ans;
                tmp = "";
            }
            else tmp += str[i];
        }

        if(tmp != "")
        {
            if(ans == "") ans = tmp;
            else ans = tmp + " " + ans;
        }

        return ans;
    }
};