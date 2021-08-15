class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(); 
        int m = t.size(); 
        map <char , int> ms , mt; 
        for(int i=0;i<m;i++)
        {
            mt[t[i]]++; 
        }
        int l = 0; 
        int L = 0; 
        int R = n-1; 
        int ans = INT_MAX; 
        for(int i=0;i<n;i++)
        {
            ms[s[i]]++; 
            int f = 1; 
            while(f && l<=i)
            {
                for(int j=0;j<26;j++)
                {
                    //cout<<ms['A'+j]<<" "<<mt['A'+j]<<endl; 
                    if(ms['A'+j] < mt['A'+j])
                    {
                        f = 0; 
                        break; 
                    }
                }
                for(int j=0;j<26;j++)
                {
                    //cout<<ms['A'+j]<<" "<<mt['A'+j]<<endl; 
                    if(ms['a'+j] < mt['a'+j])
                    {
                        f = 0; 
                        break; 
                    }
                }
                if(f==1)
                {
                    if(i-l+1 < ans)
                    {
                        ans = i-l+1; 
                        L = l; 
                        R = i; 
                    }
                    ms[s[l]]--; 
                    l++; 
                }
            }
            //cout<<ans<<" "<<i<<endl; 
        }
        if(ans==INT_MAX)
            return ""; 
        string res; 
        for(int i=L;i<=R;i++)
            res.push_back(s[i]); 
        return res; 
    }
};