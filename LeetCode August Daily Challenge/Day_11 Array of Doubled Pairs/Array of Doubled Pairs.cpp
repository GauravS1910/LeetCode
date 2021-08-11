class Solution {
public:
    bool canReorderDoubled(vector<int>& a) {
        int n = a.size(); 
        map <int , int> m; 
        sort(a.begin() , a.end()); 
        for(int i=0;i<n;i++)
        {
            m[a[i]]++; 
        }
        for(int i=0;i<n;i++)
        {
            if(m[a[i]] > 0)
            {
                if(m[2*a[i]] > 0)
                {
                    m[2*a[i]]--; 
                    m[a[i]]--; 
                }   
            }
        }
        for(int i=0;i<n;i++)
            if(m[a[i]])
                return false; 
        return true; 
    }
};


