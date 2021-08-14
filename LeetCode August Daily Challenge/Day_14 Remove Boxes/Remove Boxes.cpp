class Solution {
public:
    
    int dp[101][101][101]; 
    
    int removeBoxes(vector<int>& b) {
        if(b.size()==0)
            return 0; 
        int n = b.size();  
        return get(b , 0 , n-1 , 0); 
    }
    
    int get(vector<int>& b , int l , int r , int s)
    {
        if(l > r)
            return 0; 
        else if(l==r)
            return (s+1)*(s+1); 
        else if(dp[l][r][s]!=0)
            return dp[l][r][s]; 
        else
        {
            int ma = (s+1)*(s+1) + get(b , l+1 , r , 0); 
            for(int i=l+1;i<=r;i++)
            {
                if(b[l]==b[i])
                {
                    ma = max(ma , get(b , l+1 , i-1 , 0) + get(b , i , r , s+1)); 
                }
            }
            return dp[l][r][s] = ma; 
        }
    }
    
};