class NumArray {
public:
    
    vector <int> fun; 
    int size , n; 
    
    void init(int n)
    {
        size = 1; 
        while(size < n)
            size *= 2; 
        fun.assign(2*size , 0); 
    }
    
    void build(vector<int>&a , int x , int lx , int rx)
    {
        if(rx-lx==1)
        {
            if(lx < a.size())
                fun[x] = a[lx]; 
            return; 
        }
        int m = lx + (rx-lx)/2; 
        build(a , 2*x+1 , lx , m); 
        build(a , 2*x+2 , m , rx); 
        fun[x] = fun[2*x+1] + fun[2*x+2]; 
    }
    
    int sums(int l , int r , int x , int lx , int rx)
    {
        if(lx >= r || l >= rx)
            return 0; 
        if(lx >= l && rx <= r)
            return fun[x]; 
        int m = lx + (rx-lx)/2; 
        int s1 = sums(l , r , 2*x+1 , lx , m); 
        int s2 = sums(l , r , 2*x+2 , m , rx); 
        return s1+s2; 
    }
    
    NumArray(vector<int>& a) {
        n = a.size(); 
        init(n); 
        build(a , 0 , 0 , size); 
    }
    
    int sumRange(int l, int r) {
        int ans = sums(l , r+1 , 0 , 0 , size); 
        return ans; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */