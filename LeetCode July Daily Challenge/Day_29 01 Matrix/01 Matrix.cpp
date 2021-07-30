class Solution {
public:
    
    int n , m;
    int dx[4] = {0 , 1 , 0 , -1}; 
    int dy[4] = {1 , 0 , -1 , 0}; 
    
    bool isValid(int x , int y)
    {
        if(x>=0 && x<n && y>=0 && y<m)
        {
            return true; 
        }
        return false; 
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        n = a.size(); 
        m = a[0].size(); 
        vector <vector<int> > dp(n , vector<int>(m , 0));  
        int vis[n][m]; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = INT_MAX; 
            }
        }
        queue <pair<int , int> > bfs; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    dp[i][j] = 0; 
                    bfs.push({i , j}); 
                }
            }
        }
        while(bfs.size())
        {
            int x = bfs.front().first; 
            int y = bfs.front().second; 
            bfs.pop(); 
            for(int i=0;i<4;i++)
            {
                int X = x + dx[i]; 
                int Y = y + dy[i]; 
                if(isValid(X ,Y))
                {
                    if(dp[X][Y] > dp[x][y] + 1)
                    {
                        dp[X][Y] = dp[x][y] + 1; 
                        bfs.push({X , Y}); 
                    }
                }
            }
        }
        return dp; 
    }
};