class Solution {
public:
    bool checkV4(string s)
    {
        int n = s.length();
        if(n < 1 || n>3) return false;
        // leading zero
        if(s[0] == '0' && n>1) return false;

        int num = stoi(s);
        if(num>=0 && num<=255) return true;
        return false;
    }

    bool checkV6(string s)
    {
        int n = s.length();
        if(n<1 || n>4) return false;

        for(int i=0;i<n;i++)
        {
            if(!((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='f') || (s[i]>='A' && s[i]<='F')))
            {
                return false;
            }
        }
        return true;
    }

    string validIPAddress(string s) {
        int n = s.length();

        // Step 1, Confirming the ipV4 or ipV6
        // First I need to confirm either I should check for IPv4 or IPv6
        bool ipV4=false, ipV6=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            {
                ipV4=true;
                break;
            }
            else if(s[i]==':')
            {
                ipV6=true;
                break;
            }
        }

        // Step 2, Checking it's region, either it is IPv4 or IPv6
        if(ipV4 == true)
        {
            string curr = "";
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(s[i] != '.')
                {
                    if(!(s[i]>='0' && s[i]<='9')) return "Neither";
                    curr += s[i];
                }
                else
                {
                    if(checkV4(curr) == false)
                    {
                        return "Neither";
                    }
                    curr="";
                    cnt++;
                }
            }

            // For last region
            if(checkV4(curr) == false)
            {
                return "Neither";
            }

            if(cnt==3) return "IPv4";
        }
        else if(ipV6 == true)
        {
            string curr = "";
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                if(s[i] != ':')
                {
                    curr += s[i];
                }
                else
                {
                    if(checkV6(curr) == false)
                    {
                        return "Neither";
                    }
                    curr="";
                    cnt++;
                }
            }
            // For last region
            if(checkV6(curr) == false)
            {
                return "Neither";
            }
            if(cnt==7) return "IPv6";
        }
        return "Neither";
    }
};