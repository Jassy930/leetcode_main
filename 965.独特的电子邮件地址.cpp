/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 独特的电子邮件地址
 *
 * https://leetcode-cn.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (65.63%)
 * Total Accepted:    2.4K
 * Total Submissions: 3.7K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
    int value = 0;
    bool isUnivalTree(TreeNode *root)
    {
        value = root->val;
        isUT(root);
        return (value != -1);
    }

    void isUT(TreeNode *root)
    {
        if (root == NULL || value == -1)
            return;
        else
        {
            if (root->val != value)
                value = -1;
            else
            {
                isUT(root->left);
                isUT(root->right);
            }
        }
    }
};
