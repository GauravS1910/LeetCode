class Solution {
public:
    
    vector <vector <int> > v; 
    map <vector<int> , int> m; 
    vector <int> u; 
    
    void recur(vector <int>& a , int i)
    {
        if(m[u]==0)
        {
            v.push_back(u); 
            m[u]++; 
        }
        if(i==a.size())
            return; 
        for(int j=i;j<a.size();j++)
        {
            u.push_back(a[j]); 
            recur(a , j+1); 
            u.pop_back(); 
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        int n = a.size(); 
        sort(a.begin() , a.end()); 
        recur(a , 0); 
        return v; 
    }
};