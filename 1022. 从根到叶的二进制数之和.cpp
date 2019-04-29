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
    long long out=0;
    long long mm = pow(10,9)+7;
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return out;
        dfs(root, 0);
        return out;
    }
    
    
    void dfs(TreeNode* root, long long num){
        if(root == NULL) return;
        else if(root->left == NULL && root->right == NULL)
        {
            num = num * 2 + root->val;
            num = num % mm;
            // cout<<num<<",";
            out += num;
            out = out % mm;
        }
        else{
            num = num * 2 + root->val;
            num = num % mm;
            dfs(root->left, num);
            dfs(root->right, num);
        }
    }
};