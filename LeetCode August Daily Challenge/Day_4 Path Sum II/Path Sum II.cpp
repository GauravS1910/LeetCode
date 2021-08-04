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
    
    vector<vector<int>> v; 
    vector <int> u; 
    
    void dfs(TreeNode* root , int t)
    {
        if(root==NULL)
        {
            return; 
        }
        u.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==t)
        {
            v.push_back(u); 
        }
        dfs(root -> left , t - root->val); 
        dfs(root -> right , t - root->val); 
        u.pop_back(); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        dfs(root , t); 
        return v; 
    }
};