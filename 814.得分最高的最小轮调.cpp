/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 得分最高的最小轮调
 *
 * https://leetcode-cn.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (67.14%)
 * Total Accepted:    2K
 * Total Submissions: 3K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * 给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
 * 
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 
 * ( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
 * 
 * 
 * 示例1:
 * 输入: [1,null,0,0,1]
 * 输出: [1,null,0,null,1]
 * ⁠
 * 解释: 
 * 只有红色节点满足条件“所有不包含 1 的子树”。
 * 右图为返回的答案。
 * 
 * 
 * 
 * 
 * 
 * 示例2:
 * 输入: [1,0,1,0,0,0,1]
 * 输出: [1,null,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例3:
 * 输入: [1,1,0,1,1,0,1,0]
 * 输出: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 说明: 
 * 
 * 
 * 给定的二叉树最多有 100 个节点。
 * 每个节点的值只会为 0 或 1 。
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
class Solution
{
  public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        LRD(root, NULL, 0);
        return root;
    }

    void LRD(TreeNode *root, TreeNode *p, int a)
    {
        if (root == NULL)
            return;
        LRD(root->left, root, 0);
        LRD(root->right, root, 1);
        if (root->left == NULL && root->right == NULL && root->val == 0)
        {
            if (a == 0)
                p->left = NULL;
            else
                p->right = NULL;
        }
    }
};

// 先序遍历  Pre-order
// 中序遍历  LDR
// 后序遍历  LRD
