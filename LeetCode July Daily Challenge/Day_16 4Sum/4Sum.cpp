class Solution {
public:
    
    #define pb      push_back 
    
    vector<vector<int>> fourSum(vector<int>& a , int t) {
        int n = a.size(); 
        map<vector<int> , int> m;  
        vector<vector<int>> ans; 
        sort(a.begin() , a.end()); 
        for(int i=0;i<n;i++)
        {
            int x = a[i]; 
            for(int j=i+1;j<n;j++)
            {
                x = a[i] + a[j]; 
                int s = t - x; 
                int l = j+1; int r = n-1; 
                while(l < r)
                {
                    if(a[l] + a[r] == s)
                    {
                        vector <int> v; 
                        v.pb(a[i]); 
                        v.pb(a[j]); 
                        v.pb(a[l]); 
                        v.pb(a[r]);
                        if(m[v]==0)
                            ans.pb(v); 
                        l++;
                        m[v]++; 
                    }
                    else if(a[l] + a[r] > s)
                    {
                        r--; 
                    }
                    else 
                    {
                        l++; 
                    }
                }
            }
        }
        return ans; 
    }
};