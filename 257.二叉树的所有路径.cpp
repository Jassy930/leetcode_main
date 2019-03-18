/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.23%)
 * Total Accepted:    6.6K
 * Total Submissions: 11.6K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> out;

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)return out;
        stringstream ss;
        ss<<root->val;
        if(root->left == NULL && root->right == NULL)
        {
            out.push_back(ss.str());
            return out;
        }
        ShowString(root, ss.str());
        return out;
    }

    void ShowString(TreeNode* root, string s){
        if(root->left == NULL && root->right == NULL)
        {
            out.push_back(s);
        }
        else{
            if(root->left != NULL)
            {
                stringstream ss;
                ss<<s<<"->"<<root->left->val;
                ShowString(root->left, ss.str());
            }
            if(root->right != NULL)
            {
                stringstream ss;
                ss<<s<<"->"<<root->right->val;
                ShowString(root->right, ss.str());
            }
        }
    }
};

