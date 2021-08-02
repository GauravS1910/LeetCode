class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size(); 
        vector <int> v; 
        map <int , int> m; 
        int r , x; 
        for(int i=0;i<n;i++)
        {
            r = t - a[i]; 
            if(m[r])
            {
                x = a[i]; 
                v.push_back(i); 
                v.push_back(m[r]-1); 
                break; 
            }
            m[a[i]] = i+1; 
        }
        return v; 
    }
};