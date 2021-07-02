class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size(); 
        int l = -1 , r = n; 
        for(int i=0;i<n;i++)
        {
            if(a[i] > x)
            {
                r = i; 
                l = i-1; 
                break; 
            }
        }
        if(r==n)
            l = n-1; 
        cout<<l<<" "<<r<<endl; 
        vector <int> v; 
        while(v.size() < k)
        {
            if(l < 0)
            {
                v.push_back(a[r]); 
                r++; 
            }
            else if(r >= n)
            {
                v.push_back(a[l]); 
                l--; 
            }
            else
            {
                if(abs(a[l]-x) <= abs(a[r]-x))
                {
                    v.push_back(a[l]); 
                    l--;  
                }
                else
                {
                    v.push_back(a[r]); 
                    r++; 
                }
            }
        }
        sort(v.begin() , v.end()); 
        return v;  
    }
};