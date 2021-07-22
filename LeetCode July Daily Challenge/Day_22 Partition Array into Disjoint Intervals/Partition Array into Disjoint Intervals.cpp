class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int n = a.size(); 
        int l[n] , r[n]; 
        l[0] = a[0]; 
        r[n-1] = a[n-1]; 
        for(int i=1;i<n;i++)
            l[i] = max(a[i] , l[i-1]); 
        for(int i=n-2;i>=0;i--)
            r[i] = min(a[i] , r[i+1]);
        for(int i=0;i<n-1;i++)
        {
            if(l[i] <= r[i+1])
                return i+1; 
        }
        return n-1; 
    }
};