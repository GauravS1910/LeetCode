class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int n = a.size(); 
        int m = a[0].size(); 
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                a[i][j] += a[i][j-1]; 
            }
        }
        int ans = INT_MIN;  
        for(int s=0;s<m;s++)
        {
            for(int j=s;j<m;j++)
            {
                int c = 0;
                set<int> S = {0};
                int pref_sum = 0;
                for(int i=0;i<n;i++)
                {
                    int curr = a[i][j]; 
                    if(s > 0)
                    {
                        curr -= a[i][s - 1]; 
                    }
                    pref_sum += curr; 
                    auto itr = S.lower_bound(pref_sum-k);
                    if(itr!=S.end())
                        ans = max(ans,pref_sum-(*itr));
                    S.insert(pref_sum); 
                }
            }
        }
        return ans; 
    }
};