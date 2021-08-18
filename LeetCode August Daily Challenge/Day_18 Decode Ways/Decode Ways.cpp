class Solution {
public:
    
    int dp[101]; 
    
    int recur(string s , int i)
    {
        if(dp[i]!=-1)
            return dp[i]; 
        if(i==s.size())
        {
            return 1; 
        }
        int t = 0; 
        if(s[i]>='1' && s[i+1]<='9')
        {
            t = recur(s , i+1); 
        }
        if(i+1<s.size() && s[i]=='1')
        {
            if(s[i+1]>='0' && s[i+1]<='9')
                t += recur(s , i+2); 
        }
        if(i+1<s.size() && s[i]=='2')
        {
            if(s[i+1]>='0' && s[i+1]<='6')
                t += recur(s , i+2); 
        } 
        return (dp[i] = t);  
    }
    
    int numDecodings(string s) {
        memset(dp , -1 , sizeof(dp)); 
        int ans = recur(s , 0); 
        return ans; 
    }
};