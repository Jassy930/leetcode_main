/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (56.95%)
 * Total Accepted:    4.2K
 * Total Submissions: 7.3K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 
 * 
 * 注意：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> out;
        vector<TreeNode*> tn;
        tn.push_back(root);
        while(tn.size()!=0)
        {
            double total=0;
            vector<TreeNode*> newtn;
            for(int i=0; i<tn.size(); i++)
            {
                if(tn.at(i)->left!= NULL) newtn.push_back(tn.at(i)->left);
                if(tn.at(i)->right!= NULL) newtn.push_back(tn.at(i)->right);
                total+=tn.at(i)->val;
            }
            out.push_back(total/tn.size());
            tn.clear();
            tn = newtn;
        }
        return out;
    }
};

