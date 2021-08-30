class Solution {
public:
    int maxCount(int n, int m, vector<vector<int>>& ops) {
        int N = n; 
        int M = m; 
        for(int i=0;i<ops.size();i++)
        {
            N = min(N , ops[i][0]); 
            M = min(M , ops[i][1]); 
        }
        return N*M; 
    }
};