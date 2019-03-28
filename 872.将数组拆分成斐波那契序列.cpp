/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 将数组拆分成斐波那契序列
 *
 * https://leetcode-cn.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (56.60%)
 * Total Accepted:    3.1K
 * Total Submissions: 5.6K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * 请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 * 
 * 
 * 
 * 举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
 * 
 * 如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 
 * 如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的两颗树可能会有 1 到 100 个结点。
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> seq1 = getseq(root1);
        vector<int> seq2 = getseq(root2);
        if (seq1.size() != seq2.size())
            return false;
        for (int i = 0; i < seq1.size(); i++)
        {
            if (seq1.at(i) != seq2.at(i))
                return false;
        }
        return true;
    }

    vector<int> getseq(TreeNode *root)
    {
        vector<int> out;
        if (root == NULL)
            return out;
        else if (root->left == NULL && root->right == NULL)
        {
            out.push_back(root->val);
            return out;
        }
        else
        {
            auto ll = getseq(root->left);
            auto rr = getseq(root->right);
            out.insert(out.end(), ll.begin(), ll.end());
            out.insert(out.end(), rr.begin(), rr.end());
            return out;
        }
    }
};
