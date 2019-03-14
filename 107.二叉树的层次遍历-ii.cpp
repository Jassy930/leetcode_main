/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.15%)
 * Total Accepted:    11K
 * Total Submissions: 18.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> out;
        if(root == NULL) return out;
        vector<int> layer1;
        layer1.push_back(root->val);
        out.push_back(layer1);
        queue<TreeNode*> nodeq;
        if(root->left != NULL) nodeq.push(root->left);
        if(root->right != NULL) nodeq.push(root->right);
        while(nodeq.size()!=0)
        {
            vector<int> layer;
            queue<TreeNode*> nodeqnew;
            while(nodeq.size()!=0)
            {
                TreeNode* p = nodeq.front();
                nodeq.pop();
                layer.push_back(p->val);
                if(p->left !=NULL) nodeqnew.push(p->left);
                if(p->right !=NULL) nodeqnew.push(p->right);
            }
            out.push_back(layer);
            nodeq=nodeqnew;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};

