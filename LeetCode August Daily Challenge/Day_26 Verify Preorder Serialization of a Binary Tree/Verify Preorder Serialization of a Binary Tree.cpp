class Solution {
public:
    bool isValidSerialization(string s) {
        vector <int> v; 
        int n = s.size();
        for(int i=0;i<n;)
        {
            if(s[i]=='#')
            {
                v.push_back(0); 
                i++; 
            }
            else if(s[i]==',')
                i++; 
            else
            {
                int j = i;
                v.push_back(1); 
                while(j<n && s[j]!=',')
                    j++; 
                i = j; 
            }
        }
        stack <int> st;
        if(v.size()==1 && v[0]==0)
            return true; 
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
                st.push(2); 
            else
            {
                if(st.size()==0)
                    return false; 
                while(st.size())
                {
                    int x = st.top(); 
                    st.pop(); 
                    if(x==2)
                    {
                        st.push(1); 
                        break; 
                    }
                }
            }
            if(st.size()==0 && i<v.size()-1)
                return false; 
        }
        if(st.size()==0)
            return true; 
        return false; 
    }
};