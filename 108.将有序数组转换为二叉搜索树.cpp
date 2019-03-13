/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (61.30%)
 * Total Accepted:    13.9K
 * Total Submissions: 22.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        TreeNode *p = new TreeNode(0);
        int i = 0;
        int k = nums.size() - 1;
        int m = (i + k) / 2;
        p->val = nums.at(m);
        if (m > i)
        {
            vector<int> n{nums.begin(), nums.begin() + m};
            BuildBST(p, n, 0);
        }
        if (k > m)
        {
            vector<int> n{nums.begin() + m + 1, nums.end()};
            BuildBST(p, n, 1);
        }
        return p;
    }

    void BuildBST(TreeNode *p, vector<int> &nums, int dir)
    {
        int m = (nums.size() - 1) / 2;
        if (dir == 0)
        {
            p->left = new TreeNode(nums.at(m));
            p = p->left;
        }
        else
        {
            p->right = new TreeNode(nums.at(m));
            p = p->right;
        }
        if (m > 0)
        {
            vector<int> n{nums.begin(), nums.begin() + m};
            BuildBST(p, n, 0);
        }
        if (m < nums.size() - 1)
        {
            vector<int> n{nums.begin() + m + 1, nums.end()};
            BuildBST(p, n, 1);
        }
    }
};
