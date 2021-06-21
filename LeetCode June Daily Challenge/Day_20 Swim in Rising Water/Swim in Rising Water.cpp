

// BinarySearch and BFS

class Solution {
public:
    
    int reachable(int m , vector<vector<int>>& g , int n)
    {
        queue <pair<int , int> > bfs; 
        vector<vector<int>> vis(n , vector<int>(n , 0)); 
        int dir[4][2] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}}; 
        bfs.push({0 , 0}); 
        while(bfs.size())
        {
            int x = bfs.front().first; 
            int y = bfs.front().second;
            bfs.pop(); 
            if(g[x][y] <= m)
            {
                if(x==n-1 && y==n-1)
                    return true; 
                for(auto d : dir)
                {
                    int i = x + d[0]; 
                    int j = y + d[1];
                    if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j])
                    {
                        vis[i][j] = 1; 
                        bfs.push({i , j}); 
                    }
                }
            }
        }
        return false; 
    }
    
    int swimInWater(vector<vector<int>>& g) 
    {
        int n = g.size(); 
        int l = g[0][0]; int r = n*n-1; 
        while(l < r)
        {
            int m = l + (r-l)/2;  
            if(reachable(m , g , n))
            {
                r = m; 
            }
            else
            {
                l = m+1; 
            }
        }
        return r; 
    }
};