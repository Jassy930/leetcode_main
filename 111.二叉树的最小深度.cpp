/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (37.00%)
 * Total Accepted:    11.1K
 * Total Submissions: 30.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int minout = -1;
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            minD(root, 1);
        return minout;
    }

    void minD(TreeNode *root, int deep)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (minout == -1)
                minout = deep;
            else
                minout = min(minout, deep);
            return;
        }
        if (root->left != NULL)
            minD(root->left, deep + 1);
        if (root->right != NULL)
            minD(root->right, deep + 1);
    }
};
