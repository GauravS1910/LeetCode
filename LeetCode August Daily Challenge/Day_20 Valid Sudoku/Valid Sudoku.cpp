class Solution {
public:
    
    bool isValid(int x , int y , vector<vector<char>>& g)
    {
        char c = g[x][y]; 
        int cc = 0; 
        for(int j=0;j<9;j++)
        {
            if(g[x][j]==c)
                cc++; 
        }
        if(cc > 1)
            return false; 
        cc = 0; 
        for(int i=0;i<9;i++)
        {
            if(g[i][y]==c)
                cc++; 
        }
        if(cc > 1)
            return false; 
        cc = 0; 
        x = x/3 * 3; 
        y = y/3 * 3; 
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(g[i][j]==c)
                    cc++; 
            }
        }
        if(cc > 1)
            return false;  
        return true; 
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' && !isValid(i , j , board))
                {
                    return false; 
                }
            }
        }
        return true; 
    }
};