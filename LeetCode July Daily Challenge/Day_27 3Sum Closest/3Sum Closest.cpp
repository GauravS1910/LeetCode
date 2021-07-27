class Solution {
public:
    int threeSumClosest(vector<int>& a, int T) {
        int n = a.size(); 
        sort(a.begin() , a.end()); 
        int ans = INT_MAX; 
        int ss = 0; 
        for(int i=0;i<n-2;i++)
        {
            int s = a[i]; 
            int t = T - s; 
            int l = i+1; int r = n-1; 
            while(l < r)
            {
                int S = s + a[l] + a[r]; 
                int d = abs(T - S); 
                if(d < ans)
                {
                    ss = S; 
                    ans = d;
                }
                if(a[l]+a[r] >= t)
                    r--; 
                else
                    l++; 
            }
        }
        return ss; 
    }
};