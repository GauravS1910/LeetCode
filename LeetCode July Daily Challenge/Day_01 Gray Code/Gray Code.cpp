
// Using BackTracking

class Solution {
public:
    
    #define pb      push_back
    
    bool help(vector<int>& r , int n , unordered_set<int>& p)
    {
        //cout<<r.size()<<endl;  
        if(r.size()==(1<<n))
            return true; 
        int c = r[r.size()-1]; 
        for(int i=0;i<n;i++)
        {
            int ne = c ^ (1<<i); 
            if(p.find(ne)==p.end())
            {
                p.insert(ne); 
                r.pb(ne); 
                if(help(r , n , p))
                    return true; 
                p.erase(ne); 
                r.pop_back(); 
            }
        }
        return false; 
    }
    
    vector<int> grayCode(int n) {
        vector <int> r; 
        r.pb(0); 
        unordered_set<int> p; 
        p.insert(0); 
        help(r , n , p); 
        return r; 
    }
};