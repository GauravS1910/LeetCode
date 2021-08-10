class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(); 
        int l[n+1] , r[n+2]; 
        l[0] = r[n+1] = 0; 
        for(int i=1;i<=n;i++)
        {
            l[i] = l[i-1]; 
            if(s[i-1]=='0')
            {
                l[i] = l[i-1] + 1; 
            }
        }
        for(int i=n;i>=1;i--)
        {
            r[i] = r[i+1]; 
            if(s[i-1]=='0')
                r[i] = r[i+1] + 1; 
        }
        int ans = INT_MAX;  
        for(int i=0;i<=n;i++)
        {
            ans = min(ans , (i-l[i]) + r[i+1] ); 
        }
        return ans; 
    }
};