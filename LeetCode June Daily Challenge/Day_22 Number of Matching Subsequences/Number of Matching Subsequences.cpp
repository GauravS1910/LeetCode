
// Approach : Using binary search!!

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) 
    {
        int n = s.size(); 
        int m = w.size(); 
        int ans = m; 
        vector <int> v[26]; 
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'].push_back(i); 
        }
        for(int i=0;i<m;i++)
        {
            string t = w[i]; 
            int x = -1; 
            for(int j=0;j<t.size();j++)
            {
                int pos = t[j] - 'a'; 
                vector <int>::iterator upper; 
                upper = upper_bound(v[pos].begin() , v[pos].end() , x); 
                if(upper==v[pos].end())
                {
                    ans--; 
                    break; 
                }
                else
                {
                    x = *upper; 
                }
            }
        }
        return ans; 
    }
};