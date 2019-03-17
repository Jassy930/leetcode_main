/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 最高的广告牌
 *
 * https://leetcode-cn.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (44.53%)
 * Total Accepted:    552
 * Total Submissions: 1.2K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 * 
 * 如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
 * 
 * 我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
 * 
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4], x = 4, y = 3
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：root = [1,2,3,null,4], x = 2, y = 3
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点数介于 2 到 100 之间。
 * 每个节点的值都是唯一的、范围为 1 到 100 的整数。
 * 
 * 
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
    int xx;
    int yy;
    int xxD = 0;
    int yyD = 0;
    int xxF = 0;
    int yyF = 0;
    bool isCousins(TreeNode *root, int x, int y)
    {
        xx = x;
        yy = y;
        maxD(root, 0, root->val);
        if (xxD == yyD && xxF!=yyF)
            return true;
        else
            return false;
    }

    void maxD(TreeNode *root, int deep, int FF)
    {
        if (root == NULL)
            return;
        if (root->val == xx)
        {
            xxD = deep;
            xxF = FF;
        }
        if (root->val == yy)
        {
            yyD = deep;
            yyF = FF;
        }
        maxD(root->left, deep + 1, root->val);
        maxD(root->right, deep + 1, root->val);
    }
};
