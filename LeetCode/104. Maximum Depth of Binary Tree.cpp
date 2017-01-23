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
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,1});
        int mx=0;
        while (!s.empty())
        {
            auto t=s.top();
            s.pop();
            mx = max(mx, t.second);
            if (t.first->left!=NULL)
                s.push ({t.first->left, t.second+1});
            if (t.first->right!=NULL)
                s.push ({t.first->right, t.second+1});
        }
        return mx;
    }
};
