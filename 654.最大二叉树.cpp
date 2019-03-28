/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 *
 * https://leetcode-cn.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (72.48%)
 * Total Accepted:    3K
 * Total Submissions: 4.1K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
 * 
 * 
 * 二叉树的根是数组中的最大元素。
 * 左子树是通过数组中最大值左边部分构造出的最大二叉树。
 * 右子树是通过数组中最大值右边部分构造出的最大二叉树。
 * 
 * 
 * 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
 * 
 * Example 1:
 * 
 * 
 * 输入: [3,2,1,6,0,5]
 * 输入: 返回下面这棵树的根节点：
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的数组的大小在 [1, 1000] 之间。
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        int i = 0;
        int maxnum = nums.at(0);
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums.at(k) > maxnum)
            {
                i = k;
                maxnum = nums.at(k);
            }
        }
        TreeNode *root = new TreeNode(maxnum);
        if (i != 0)
        {
            vector<int> ll(nums.begin(), nums.begin() + i);
            root->left = constructMaximumBinaryTree(ll);
        }
        if (i != nums.size() - 1)
        {
            vector<int> rr(nums.begin() + i + 1, nums.end());
            root->right = constructMaximumBinaryTree(rr);
        }
        return root;
    }
};
