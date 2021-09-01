class Solution {
public:
    
    int c = 0; 
    int vis[100010]; 
    
    void dfs(vector<int>& a , int i)
    {
        vis[i] = 1; 
        c++; 
        int u = a[i];  
        if(vis[u]==0)
            dfs(a , u); 
    }
    
    int arrayNesting(vector<int>& a) {
        int n = a.size(); 
        int ans = 0; 
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                c = 0;
                dfs(a , i); 
            }
            ans = max(ans , c); 
        }
        return ans; 
    }
};