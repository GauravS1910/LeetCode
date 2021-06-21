
// Simplest Solution!!

class Solution {
public:
    
    #define pb      push_back
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v; 
        vector<int>u; 
        u.pb(1);
        v.pb(u); 
        if(n==1)
        {
            return v; 
        }
        u.pb(1); 
        v.pb(u); 
        for(int i=3;i<=n;i++)
        {
            vector <int> x; 
            x.pb(1); 
            for(int j=1;j<u.size();j++)
            {
                x.pb(u[j] + u[j-1]); 
            }
            x.pb(1); 
            v.pb(x); 
            u = x; 
        }
        return v; 
    }
};