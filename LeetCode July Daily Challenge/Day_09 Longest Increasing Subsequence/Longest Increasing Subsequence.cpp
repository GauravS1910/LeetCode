class Solution {
public:
    int lengthOfLIS(vector<int>& a) 
    {
        int n = a.size();
        vector <int> c;
        c.push_back(a[0]); 
        for(int i=1;i<n;i++)
        {
            if(a[i] > c[c.size()-1])
            {
                c.push_back(a[i]); 
            }
            else
            {
                int ind = lower_bound(c.begin() , c.end() , a[i]) - c.begin(); 
                c[ind] = a[i]; 
            }
        }
        return c.size(); 
    }
};