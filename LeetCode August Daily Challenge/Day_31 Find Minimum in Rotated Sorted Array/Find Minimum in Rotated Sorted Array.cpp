class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size(); 
        int l = 0, r = n-1; 
        while(r-l > 1)
        {
            int m = l + (r-l)/2; 
            if(a[m] > a[l] && a[m] > a[r])
            {
                l = m; 
            }
            else if(a[m] < a[l] && a[m] < a[r])
            {
                r = m; 
            }
            else if(a[m] > a[l] && a[m] < a[r])
            {
                r = m; 
            }
            else
                l = m; 
        }
        return min(a[l] , a[r]);  
    }
};