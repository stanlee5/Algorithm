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
    pair<TreeNode*,int> check (TreeNode *n, TreeNode *p, TreeNode *q)
    {
        if (n==NULL) return {NULL,0};
        auto l = check(n->left, p, q);
        auto r = check(n->right, p, q);
        if (l.second==3) return l;
        if (r.second==3) return r;
        int var=l.second+r.second+(n==p?1:0)+(n==q?2:0);
        return {n,var};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = check (root,p,q);
        return res.first;
    }
};
