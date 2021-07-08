class Solution {
public:
    
    int dp[1010][1010]; 
    
    int findLength(vector<int>& a, vector<int>& b) 
    {
        int n = a.size(); int m = b.size(); 
        int ans = 0; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;  
                }
                else
                {
                    dp[i][j] = 0;  
                }
                ans = max(ans , dp[i][j]); 
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout<<dp[i][j]<<" "; 
        //     } cout<<endl; 
        // }
        return ans; 
    }
};