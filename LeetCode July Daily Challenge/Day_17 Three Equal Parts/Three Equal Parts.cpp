class Solution {
public:
    vector<int> threeEqualParts(vector<int>& a) {
        int n = a.size(); 
        int o = 0; 
        int f , s , t; 
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                o++; 
            }
        }
        vector <int> ans;
        ans.push_back(-1);
        ans.push_back(-1);  
        if(o%3!=0)
        {
            return ans; 
        }
        if(o==0)
        {
            ans[0] = 0; 
            ans[1] = 2; 
            return ans; 
        }
        int x = 0; 
        int y = o/3; 
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                x++; 
                if(x==1)
                {
                    f = i; 
                }
                else if(x==1+y)
                {
                    s = i; 
                }
                else if(x==1+2*y)
                {
                    t = i; 
                }
                // if(x==y*2)
                // {
                //     ans[1] = i+1; 
                // }
                // if(x==y)
                // {
                //     ans[0] = i; 
                // }
            }
        }
        // cout<<f<<" "<<s<<" "<<t<<endl; 
        while(t < a.size())
        {
            if(a[f]==a[s] && a[s]==a[t])
            {
                f++; s++; t++; 
            }
            else
            {
                ans[0] = -1; 
                ans[1] = -1; 
                return ans; 
            }
        }
        ans[0] = f-1; 
        ans[1] = s; 
        return ans; 
    }
};