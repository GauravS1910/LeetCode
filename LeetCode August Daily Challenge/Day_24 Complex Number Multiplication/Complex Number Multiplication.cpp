class Solution {
public:
    
    #define pb      push_back 
    
    string complexNumberMultiply(string s, string t) {
        
        int x = 0; 
        if(s[0]=='-')
        {
            int ind = 1; 
            while(s[ind]!='+')
            {
                x = x*10 + (s[ind]-'0'); 
                ind++; 
            }
            x = -1*x; 
        }
        else
        {
            int ind = 0; 
            while(s[ind]!='+')
            {
                x = x*10 + (s[ind]-'0'); 
                ind++; 
            }
        }
        
        int y = 0;  
        if(t[0]=='-')
        {
            int ind = 1; 
            while(t[ind]!='+')
            {
                y = y*10 + (t[ind]-'0'); 
                ind++; 
            }
            y = -1*y; 
        }
        else
        {
            int ind = 0; 
            while(t[ind]!='+')
            {
                y = y*10 + (t[ind]-'0'); 
                ind++; 
            }
        }
        
        int xy = x*y; 
        
        int p = 0; 
        int ind = s.size()-2; 
        int f = 1; 
        while(s[ind]!='+' && s[ind]!='-')
        {
            p = p + (s[ind]-'0')*f; 
            f = f*10; 
            ind--; 
        }
        if(s[ind]=='-')
            p = -1*p;
        
        int q = 0; 
        ind = t.size()-2;
        f = 1; 
        while(t[ind]!='+' && t[ind]!='-')
        {
            q = q + (t[ind]-'0')*f; 
            f = f*10; 
            ind--; 
        }
        if(t[ind]=='-')
            q = -1*q; 
    
        int pq = p*q; 
        
        int r = xy - pq; 
        int i = p*y + q*x; 
        
        string ans; 
        if(r<0)
            ans.pb('-'); 
        string h = to_string(abs(r));
        ans += h; 
        ans.pb('+'); 
        if(i < 0)
            ans.pb('-'); 
        h = to_string(abs(i)); 
        ans += h; 
        ans.pb('i'); 
        return ans; 
    }
};