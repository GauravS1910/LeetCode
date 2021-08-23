/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int f = 0;
    map <int , int> mp; 
    
    void dfs(TreeNode* root , int k)
    {
        if(root==NULL)
            return; 
        int v = root->val; 
        if(mp[k-v])
        {
            f = 1; 
            return; 
        }
        mp[v]++; 
        dfs(root->left , k); 
        dfs(root->right , k); 
    }
    
    bool findTarget(TreeNode* root, int k) {
        dfs(root , k); 
        if(f)
            return true; 
        return false; 
    }
};