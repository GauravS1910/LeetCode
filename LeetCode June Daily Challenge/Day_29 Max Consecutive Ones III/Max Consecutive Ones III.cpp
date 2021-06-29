class Solution {
public:
    int longestOnes(vector<int>& a, int k) 
    {
        int n = a.size(); 
        int c = 0; 
        int l = 0; 
        int ans = 0;  
        int K = k; 
        for(int r=0;r<n;r++)
        {
            if(a[r]==0)
            {
                if(k > 0)
                {
                    k--; 
                    c++; 
                }
                else
                {
                    if(K==0)
                    {
                        c = 0; 
                        continue; 
                    }
                    while(l < r)
                    {
                        if(a[l]==0)
                        {
                            l++; 
                            break; 
                        }
                        else if(a[l]==1)
                        {
                            c--; 
                        }
                        l++; 
                    }
                }
            }
            else
            {
                c++; 
            }
            //cout<<c<<" "<<l<<endl; 
            ans = max(ans , c); 
        }
        return ans; 
    }
};