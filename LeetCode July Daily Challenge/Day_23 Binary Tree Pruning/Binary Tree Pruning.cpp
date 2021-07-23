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
    
    bool recur(TreeNode* root)
    {
        if(root==NULL)
            return false; 
        bool l = recur(root->left); 
        bool r = recur(root->right); 
        if(l==false)
            root->left = NULL; 
        if(r==false)
            root->right = NULL; 
        return root->val==1 || l || r; 
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return recur(root) ? root : NULL; 
    }
};