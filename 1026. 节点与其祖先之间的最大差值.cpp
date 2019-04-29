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
    int m = 0;
    int n = 100000;
    int maxdiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        maxT(root);
        minT(root);
        return maxdiff;
    }
    
    int maxT(TreeNode* root)
    {
        if(root == NULL) return m;
        int k = root->val;
        if(root->left != NULL) k = max(maxT(root->left), k);
        if(root->right != NULL ) k = max(maxT(root->right), k);
        maxdiff = max(maxdiff, abs(k-root->val));
        return k;
    }
    
    int minT(TreeNode* root)
    {
        if(root == NULL) return n;
        int k = root->val;
        if(root->left != NULL) k = min(minT(root->left), k);
        if(root->right != NULL ) k = min(minT(root->right), k);
        maxdiff = max(maxdiff, abs(k-root->val));
        return k;
    }
};