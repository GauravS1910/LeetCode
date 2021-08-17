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
    
    int ans = 0; 
    
    void dfs(TreeNode* root , int ma)
    {
        if(root->val >= ma)
            ans++; 
        if(root->left)
        {
            dfs(root->left , max(ma , root->left->val)); 
        }
        if(root->right)
        {
            dfs(root->right , max(ma , root->right->val)); 
        }
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root , root->val); 
        return ans; 
    }
};
