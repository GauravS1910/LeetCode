
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    #define pb      push_back 
    
    vector<vector<int>> levelOrder(Node* root) {
        vector <vector<int> > v; 
        if(root==NULL)
            return v; 
        queue <Node*> bfs; 
        bfs.push(root); 
        vector <int> u; 
        u.pb(root->val);
        while(bfs.size())
        {
            int n = bfs.size(); 
            u.clear();
            for(int i=0;i<n;i++)
            {
                Node* x = bfs.front();
                bfs.pop(); 
                u.pb(x->val); 
                for(int i=0;i<x->children.size();i++)
                {
                    bfs.push(x->children[i]); 
                }
            }
            v.pb(u); 
        }
        return v; 
    }
};