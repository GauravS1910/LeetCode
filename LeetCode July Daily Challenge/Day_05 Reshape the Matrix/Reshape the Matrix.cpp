class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& a, int r, int c) {
        int n = a.size(); 
        int m = a[0].size(); 
        if((n*m)!=(r*c))
            return a; 
        vector <int> u; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                u.push_back(a[i][j]); 
        }
        vector<vector<int>> v (r , vector<int>(c , 0)); 
        int x = 0; 
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                v[i][j] = u[x]; 
                x++; 
            }
        }
        return v; 
    }
};