class Solution {
public:
    
    #define pb      push_back
    
    struct val{
        int va; 
        int ind; 
        int v0; 
        int v1; 
    };
    
    static bool compare(val a , val b)
    {
        return (a.va < b.va); 
    }
    
    int candy(vector<int>& r) {
        int n = r.size(); 
        if(n==1)
            return 1; 
        val v[n]; 
        map <int , int> mp;
        v[0].va = r[0]; 
        v[0].ind = 0; 
        v[0].v0 = -1; 
        v[0].v1 = 1; 
        mp[0] = 1; 
        for(int i=1;i<n-1;i++)
        {
            v[i].va = r[i]; 
            v[i].ind = i; 
            v[i].v0 = i-1; 
            v[i].v1 = i+1;
            mp[i] = 1; 
        }
        v[n-1].va = r[n-1];  
        v[n-1].ind = n-1;  
        v[n-1].v0 = n-2;  
        v[n-1].v1 = -1; 
        mp[n-1] = 1; 
        sort(v , v+n , compare); 
        int ans = 0; 
        for(int i=0;i<n;i++)
        {
            int x = v[i].ind; 
            int y = v[i].v0; 
            int z = v[i].v1; 
            if(y!=-1 && r[x] > r[y])
            {
                mp[x] = mp[y] + 1; 
            }
            if(z!=-1 && r[x] > r[z])
            {
                mp[x] = max(mp[x] , mp[z]+1); 
            }
        }
        for(int i=0;i<n;i++)
        {
            ans = ans + mp[i]; 
        }
        return ans; 
    }
};





