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
    
    #define mod     (1000000000+7)
    #define ll      long long
    
    ll ts = 0; 
    ll ans = 0; 
    ll s = 0; 
    
    ll recur(TreeNode* root)
    {
        if(root==NULL)
            return 0; 
        ll s1 = root->val + recur(root->left) + recur(root->right); 
        ans = max(ans , s1*(ts-s1)); 
        return s1; 
    }
    
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return; 
        ts += root->val; 
        if(root->left)
            dfs(root->left); 
        if(root->right)
            dfs(root->right); 
    }
    
    int maxProduct(TreeNode* root) {
        dfs(root); 
        ll x = recur(root); 
        ans = ans % mod; 
        return (int)ans;   
    }
};