class MapSum {
public:
    /** Initialize your data structure here. */
    map <string , int> mp; 
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key] = val; 
    }
    
    int sum(string p) {
        int ans = 0; 
        for(auto x : mp)
        {
            string s = x.first; 
            int f = 0; 
            for(int i=0;i<p.size();i++)
            {
                if(i<s.size() && s[i]==p[i])
                {
                    
                }
                else
                {
                    f = 1; 
                }
            }
            if(f==0)
            {
                ans += x.second; 
            }
        }
        return ans; 
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */