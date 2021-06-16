class Solution {
public:
    
    int f = 0;
    
    void recur(vector<int> a , int i , int x , int y , int z , int w)
    {
        //cout<<"B"<<endl; 
        if(i >= a.size())
        {
            if(x==y && x==z && x==w)
            {
                f = 1; 
                return;
            } 
            else
                return; 
        }
        
        if(f==1)
            return; 
        if(x-a[i] >= 0)
            recur(a , i+1 , x-a[i] , y , z , w); 
        if(f==1)
            return; 
        if(y-a[i] >= 0)
            recur(a , i+1 , x , y-a[i] , z , w); 
        if(f==1)
            return; 
        if(z-a[i] >= 0)
            recur(a , i+1 , x , y , z-a[i] , w); 
        if(f==1)
            return; 
        if(w-a[i] >= 0)
            recur(a , i+1 , x , y , z , w-a[i]); 
        if(f==1)
            return; 
    }
    
    bool makesquare(vector<int>& a) 
    {
        int n = a.size(); 
        if(n < 4)
            return false; 
        int s = 0; 
        sort(a.rbegin(), a.rend());
        //cout<<a[0]; 
        for(int i=0;i<n;i++)
        {
            s += a[i]; 
        }
        if(s%4!=0)
            return false; 
        //cout<<"A"<<endl; 
        recur(a , 0 , s/4 , s/4 , s/4 , s/4); 
        if(f==0)
            return false;
        return true; 
    }
};