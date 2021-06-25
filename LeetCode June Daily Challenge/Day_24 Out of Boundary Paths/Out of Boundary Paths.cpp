
// Memoization

class Solution {
public:
    
    #define ll long long
    
    ll dp[100][100][100]; 
    #define mod (1000000000+7)
    
    ll findPaths1(int n, int m, int k, int i, int j) 
    {
        if(i==n || j==m || i<0 || j<0)
        {
            return 1; 
        }
        if(k==0)
            return 0; 
        if(dp[i][j][k]!=-1)
            return dp[i][j][k] % mod;  
        
        dp[i][j][k] = findPaths1(n , m , k-1 , i+1 , j) % mod + findPaths1(n , m , k-1 , i-1 , j) % mod + findPaths1(n , m , k-1 , i , j+1) % mod + 
            findPaths1(n , m , k-1 , i , j-1) % mod; 
        
        return dp[i][j][k] % mod;  
    }
    
    int findPaths(int n, int m, int k, int i, int j) 
    {
        memset(dp , -1 , sizeof(dp)); 
        return (int)findPaths1(n , m , k , i , j);
    }
};