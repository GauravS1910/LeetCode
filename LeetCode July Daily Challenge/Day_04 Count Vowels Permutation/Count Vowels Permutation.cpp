class Solution {
public:
    
    #define ll      long long 
    #define mod     (1000000007)
    
    ll dp[5][50000]; 
    
    int countVowelPermutation(int n) {
        vector <vector<int> > v = {{1}, {0,2}, {0,1,3,4}, {2,4}, {0}}; 
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<5;i++)
            {
                if(j==1)
                    dp[i][j] = 1; 
                else 
                {
                    for(int x=0;x<v[i].size();x++)
                    {
                        //cout<<i<<" "<<v[i][x]<<endl; 
                        dp[v[i][x]][j] += dp[i][j-1];
                        dp[v[i][x]][j] %= mod; 
                    }
                }
            }
        }
        ll ans = 0;
        for(int i=0;i<5;i++)
        {
            ans += dp[i][n]; 
            ans = ans % mod; 
        } 
        return (int)ans; 
    }
};