
// Suggested Video link -> https://codeforces.com/edu/course/2/lesson/4/1

class NumArray {
public:
    int size; 
    vector <int> sums; 
    void init(int n)
    {
        size = 1; 
        while(size < n)
        {
            size = 2*size; 
        }
        int S = 2*size; 
        sums.assign(S , 0); 
    }
    
    void build(vector<int>& a , int x , int lx , int rx)
    {
        if(rx-lx==1)
        {
            if(lx < a.size())
            {
                sums[x] = a[lx]; 
            }
            return; 
        }
        int m = (lx+rx)/2; 
        build(a , 2*x+1 , lx , m);
        build(a , 2*x+2 , m , rx); 
        sums[x] = sums[2*x+1] + sums[2*x+2]; 
    }
    
    void set(int index , int val , int x , int lx , int rx)
    {
        if(rx-lx==1)
        {
            sums[x] = val; 
            return; 
        }
        int m = (lx+rx)/2; 
        if(index < m)
        {
            set(index , val , 2*x+1 , lx , m); 
        }
        else
        {
            set(index , val , 2*x+2 , m , rx); 
        }
        sums[x] = sums[2*x+1] + sums[2*x+2]; 
    }
    
    int sum(int l , int r , int x , int lx , int rx)
    {
        if(lx>=r || l>=rx)
            return 0;
        if(lx>=l && rx<=r)
            return sums[x];
        int m = (lx+rx)/2;
        int s1 = sum(l , r , 2*x+1 , lx , m);
        int s2 = sum(l , r , 2*x+2 , m , rx);
        return s1+s2;
    }
    
    NumArray(vector<int>& a) {
        int n = a.size(); 
        init(n);
        build(a , 0 , 0 , size);
    }
    
    void update(int index, int val) {
        set(index , val , 0 , 0 , size); 
    }
    
    int sumRange(int left, int right) {
        int ans = sum(left , right+1 , 0 , 0 , size);
        return ans; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */