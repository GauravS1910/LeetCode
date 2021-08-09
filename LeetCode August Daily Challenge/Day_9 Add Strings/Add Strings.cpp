class Solution {
public:
    string addStrings(string a, string b) {
        if(a.size() < b.size())
            swap(a , b); 
        int n = a.size(); 
        int m = b.size(); 
        string t; 
        for(int i=0;i<n-m;i++)
            t.push_back('0'); 
        b = t + b; 
        int c = 0; 
        string ans; 
        for(int i=n-1;i>=0;i--)
        {
            int x = a[i] - '0'; 
            int y = b[i] - '0';
            int s = x + y; 
            if(c!=0)
                s += c; 
            c = s / 10; 
            s = s % 10; 
            char ch = s + '0'; 
            ans.push_back(ch); 
        }
        if(c!=0)
        {
            char ch = c + '0'; 
            ans.push_back(ch); 
        }
        reverse(ans.begin() , ans.end()); 
        return ans; 
    }
};