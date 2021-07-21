class Solution {
public:
    
    #define pb      push_back 
    
    string pushDominoes(string d) {
        int n = d.size(); 
        int l[n] , r[n]; 
        int R = 0; 
        int L = 0; 
        r[0] = 0; 
        if(d[0]=='.')
        {
            r[0] = 0; 
        }
        else if(d[0]=='R')
        {
            r[0] = 1; 
            R = 1; 
        }
        l[n-1] = 0; 
        if(d[n-1]=='.')
        {
            l[n-1] = 0; 
        }
        else if(d[n-1]=='L')
        {
            l[n-1] = 1; 
            L = 1; 
        }
        
        for(int i=1;i<n;i++)
        {
            if(d[i]=='L')
            {
                r[i] = 0;
                R = 0; 
            }
            else if(d[i]=='R')
            {
                r[i] = 1; 
                R = 1; 
            }
            else
            {
                r[i] = r[i-1]; 
                if(R)
                    r[i] += 1;  
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<r[i]<<" "; 
        // cout<<endl; 
        for(int i=n-2;i>=0;i--)
        {
            if(d[i]=='R')
            {
                l[i] = 0; 
                L = 0; 
            }
            else if(d[i]=='L')
            {
                l[i] = 1; 
                L = 1; 
            }
            else
            {
                l[i] = l[i+1]; 
                if(L)
                    l[i] += 1;  
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<l[i]<<" "; 
        // cout<<endl; 
        string ans; 
        for(int i=0;i<n;i++)
        {
            if(l[i]==r[i])
                ans += '.'; 
            else if(r[i] < l[i])
            {
                if(r[i]==0)
                    ans += 'L'; 
                else
                    ans += 'R'; 
            }
            else
            {
                if(l[i]==0)
                    ans += 'R'; 
                else
                    ans += 'L'; 
            }
        }
        return ans; 
    }
};



