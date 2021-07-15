class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int n = a.size(); 
        if(n < 3)
        {
            return 0; 
        }
        int ans = 0; 
        sort(a.begin() , a.end()); 
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int s = a[i] + a[j]; 
                auto it = lower_bound(a.begin() , a.end() , s) - a.begin(); 
                // cout<<it<<endl; 
                ans = ans + max(0 , int(it-j-1)); 
            }
        }
        return ans; 
    }
};