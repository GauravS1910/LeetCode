class Solution {
public:
    int minSetSize(vector<int>& a) {
        int n = a.size(); 
        map <int , int> mp; 
        set <int> s; 
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;  
        }
        vector <int> v; 
        for(int i=0;i<n;i++)
        {
            if(mp[a[i]])
            {
                v.push_back(mp[a[i]]);
                mp[a[i]] = 0; 
            }
        }
        sort(v.rbegin() , v.rend()); 
        // for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<" "; 
        int ans = 0; int e = 0; 
        for(int i=0;i<v.size();i++)
        {
            ans++; 
            e = e + v[i]; 
            if(e >= n/2)
                break; 
        }
        return ans; 
    }
};