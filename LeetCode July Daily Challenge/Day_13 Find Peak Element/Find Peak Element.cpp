class Solution {
public:
    
    #define pb      push_back
    
    int findPeakElement(vector<int>& nums) {
        vector <long long> a; 
        a.pb(-1); 
        for(int i=0;i<nums.size();i++)
        {
            a.pb(nums[i]); 
        }
        //cout<<INT_MAX; 
        a.pb(-1*1e15); 
        int n = a.size(); 
        int l = 1 , r = nums.size()+1;  
        while(r-l > 1)
        {
            //cout<<l<<" "<<r<<endl;  
            int m = l + (r-l)/2; 
            if(a[m] > a[m-1] && a[m] > a[m+1])
            {
                return m-1; 
            }
            if(a[m] < a[m+1])
            {
                l = m+1; 
            }
            else if(a[m] > a[m+1])
            {
                r = m; 
            }
        }
        return l-1; 
    }
};