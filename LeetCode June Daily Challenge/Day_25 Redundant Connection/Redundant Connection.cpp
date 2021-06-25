class Solution {
public:
    
    #define pb      push_back
    
    vector <int> adj[1010]; 
    vector <int> in; 
    vector <int> low; 
    int vis[1010]; 
    int timer = 0; 
    map <pair<int , int> , int> m;
    
    void dfs(int u , int p)
    {
        vis[u] = 1;
        //cout<<u<<endl; 
        in[u] = low[u] = timer++; 
        for(int i=0;i<adj[u].size();i++)
        {
            if(adj[u][i]==p)
                continue; 
            if(vis[adj[u][i]]==1)
            {
                low[u] = min(low[u] , in[adj[u][i]]); 
            }
            else
            {
                dfs(adj[u][i] , u);
                low[u] = min(low[u] , low[adj[u][i]]); 
                if(low[adj[u][i]] > in[u])
                {
                    // v.push_back({u , adj[i][j]}); 
                    m[{u , adj[u][i]}]++; 
                    m[{adj[u][i] , u}]++; 
                }
                
            }
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        for(int i=0;i<e.size();i++)
        {
            int u = e[i][0];
            int v = e[i][1]; 
            adj[u].pb(v); 
            adj[v].pb(u); 
        }
        in.assign(1010, -1);
        low.assign(1010, -1);
        dfs(1 , -1); 
        vector <int> x; 
        for(int i=e.size()-1;i>=0;i--)
        {
            if(m[{e[i][0] , e[i][1]}]==0)
            {
                x.pb(e[i][0]); 
                x.pb(e[i][1]); 
                break; 
            }
        }
        return x; 
    }
};