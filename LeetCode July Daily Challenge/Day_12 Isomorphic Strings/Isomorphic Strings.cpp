class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(); 
        map <char , char> m; 
        map <char , int> c; 
        map <char , int> ct; 
        for(int i=0;i<n;i++)
        {
            if(c[s[i]]==0)
            {
                c[s[i]]++; 
                m[s[i]] = t[i]; 
                ct[t[i]]++; 
                if(ct[t[i]] > 1)
                    return false; 
            }
            else
            {
                if(m[s[i]]!=t[i])
                    return false; 
            }
        }
        return true; 
    }
};