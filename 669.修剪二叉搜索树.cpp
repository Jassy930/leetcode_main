/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 *
 * https://leetcode-cn.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (59.24%)
 * Total Accepted:    2.9K
 * Total Submissions: 4.8K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L)
 * 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 * 
 * ⁠ L = 1
 * ⁠ R = 2
 * 
 * 输出: 
 * ⁠   1
 * ⁠     \
 * ⁠      2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 * 
 * ⁠ L = 1
 * ⁠ R = 3
 * 
 * 输出: 
 * ⁠     3
 * ⁠    / 
 * ⁠  2   
 * ⁠ /
 * ⁠1
 * [45,30,46,10,36,null,49,8,24,34,42,48,null,4,9,14,25,31,35,41,43,47,null,0,6,null,null,11,20,null,28,null,33,null,null,37,null,null,44,null,null,null,1,5,7,null,12,19,21,26,29,32,null,null,38,null,null,null,3,null,null,null,null,null,13,18,null,null,22,null,27,null,null,null,null,null,39,2,null,null,null,15,null,null,23,null,null,null,40,null,null,null,16,null,null,null,null,null,17]\n32\n44
 * 
 * [2,0,33,null,1,25,40,null,null,11,31,34,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6]\n25\n26
 * 
 * 
 *       3
 *    1     4
 *      2
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        while (root != NULL && (root->val < L || root->val > R))
        {
            if (root->val < L)
                root = root->right;
            else if (root->val > R)
                root = root->left;
        }
        if (root->val == L)
            root->left = NULL;
        if (root->val == R)
            root->right = NULL;
        trim(root, L, R);
        return root;
    }

    void trim(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            if (root->left->val == L)
                root->left->left = NULL;
            else if (root->left->val > L)
                trim(root->left, L, R);
            else if (root->left->val < L)
            {
                root->left = root->left->right;
                trim(root, L, R);
            }
        }
        if (root->right != NULL)
        {
            if (root->right->val == R)
                root->right->right = NULL;
            else if (root->right->val < R)
                trim(root->right, L, R);
            else if (root->right->val > R)
            {
                root->right = root->right->left;
                trim(root, L, R);
            }
        }
    }
};
