class Solution {
public:
    string customSortString(string order, string str) {
        map <char , int> mp; 
        string r; 
        for(int i=0;i<str.size();i++)
        {
            mp[str[i]]++; 
        }
        for(int i=0;i<order.size();i++)
        {
            while(mp[order[i]]--)
            {
            }
        }
        for(char c='a';c<='z';c++)
        {
            while(mp[c]-- > 0)
            {
                r.push_back(c); 
            }
        }
        return r; 
    }
};