// Brute Force
class Solution {
public:
    
    vector <string> v;
    
    char s[20]; 
    int f = 0; 
    
    bool isValid(int n)
    {
        int k = 0; 
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                k++;
            else
                k--; 
            if(k < 0)
                return false; 
        }
        if(k==0)
            return true; 
        return false; 
    }
    
    void recur(int i , int n)
    {
        if(i==n)
        {
            if(isValid(n))
            {
                v.push_back(s); 
                f = 0; 
            }
            return; 
        }
        f++; 
        if(s[i]==')')
            f++; 
        s[i] = '('; 
        {
            recur(i+1 , n); 
        }
        f--; 
        if(s[i]=='(')
            f--; 
        s[i] = ')';
        {
            recur(i+1 , n);
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        recur(0 , 2*n); 
        return v; 
    }
};


// Optimized using Back-tracking

class Solution {
public:
    
    vector <string> v;
    string s; 
    
    void recur(int n , int o , int c)
    {
        if(c > o)
            return; 
        if(s.size()==n)
        {
            if(o-c==0)
            {
                v.push_back(s); 
            }
            return; 
        }
        if(o < n)
        {
            s.push_back('('); 
            recur(n , o+1 , c); 
            s.pop_back(); 
        }
        if(c < o)
        {
            s.push_back(')'); 
            recur(n , o , c+1); 
            s.pop_back(); 
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        recur(2*n , 0 , 0); 
        return v; 
    }
};