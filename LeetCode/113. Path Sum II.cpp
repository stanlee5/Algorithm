/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> path;
    
    void search (TreeNode *r, vector<vector<int>> &res, int sum, int cur)
    {
        path.push_back (r->val);
        if (cur + r->val == sum && r->left==NULL && r->right==NULL)
            res.push_back(path);
        else
        {
            if (r->left!=NULL)
                search (r->left, res, sum, cur+r->val);
            if (r->right!=NULL)
                search (r->right, res, sum, cur+r->val);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum (TreeNode* root, int sum)
    {
        vector<vector<int>> res;
        if (root==NULL) return res;
        search (root, res, sum, 0);
        return res;
    }
};
