class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size(); 
        stack <int> st; 
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]); 
            }
            else{
                char ch = st.top(); 
                if(ch==s[i]){
                    st.pop();     
                }
                else{
                    st.push(s[i]); 
                }
            }
        }
        string t; 
        while(st.size()){
            t.push_back(st.top()); 
            st.pop(); 
        }
        reverse(t.begin() , t.end()); 
        return t; 
    }
};