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
    int go (TreeNode *p, int sum, unordered_map<int,int>&m, int s)
    {
        if (p==NULL) return 0;
        int ans=(s+p->val==sum)+m[s+p->val-sum];
        m[s+p->val]++;
        ans += go(p->left,sum,m,s+p->val) + go(p->right,sum,m,s+p->val);
        m[s+p->val]--;
        return ans;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        return go (root, sum, m, 0);
    }
};
