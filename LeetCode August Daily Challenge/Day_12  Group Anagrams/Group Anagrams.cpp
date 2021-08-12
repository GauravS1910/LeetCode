class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size(); 
        vector <pair<string , string> > v(n);
        for(int i=0;i<n;i++)
        {
            v[i].second = s[i]; 
            sort(s[i].begin() , s[i].end()); 
            v[i].first = s[i]; 
        }
        sort(v.begin() , v.end()); 
        vector<vector<string>> u; 
        vector <string> a;
        a.push_back(v[0].second); 
        for(int i=1;i<n;i++)
        {
            if(v[i].first==v[i-1].first)
            {
                a.push_back(v[i].second); 
            }
            else
            {
                u.push_back(a); 
                a.clear(); 
                a.push_back(v[i].second); 
            }
        }
        u.push_back(a); 
        return u; 
    }
};