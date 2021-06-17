
// Beats 98.96% of the cpp submission

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int left, int right) 
    {
        long long n = a.size(); 
        long long c1 = 0; 
        long long c2 = 0; 
        long long ans = n*(n+1)/2; 
        for(int i=0;i<n;)
        {
            if(a[i] < left)
            {
                int c = 0;
                int j = i; 
                while(j<n && a[j] < left)
                {
                    c++; 
                    j++; 
                }
                c1 += c*(c+1)/2; 
                i = j; 
            }
            else
                i++; 
        }
        for(int i=0;i<n;)
        {
            if(a[i] > right)
            {
                int x = n-i; 
                c2 = c2 + x;
                i++; 
            }
            else
            {
                int j = i; 
                while(j<n && a[j] <= right)
                {
                    j++; 
                }
                if(j >= n)
                {
                    i = j; 
                    break; 
                }
                int x = j-i; 
                c2 = c2 + x*(n-j); 
                i = j; 
            }
        }
        cout<<ans<<" "<<c1<<" "<<c2<<endl; 
        return (int)ans-c1-c2; 
    }
};
