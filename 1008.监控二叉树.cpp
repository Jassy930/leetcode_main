/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 监控二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (67.08%)
 * Total Accepted:    473
 * Total Submissions: 689
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * 返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
 * 
 * (回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而
 * node.right 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历
 * node.right。）
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[8,5,1,7,10,12]
 * 输出：[8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= preorder.length <= 100
 * 先序 preorder 中的值是不同的。
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if(preorder.size() == 0) return NULL;
        TreeNode *root = new TreeNode(preorder.at(0));
        for(int i=1; i<preorder.size(); i++)
        {
            addNode(root, preorder.at(i));
        }
        return root;
    }

    void addNode(TreeNode* root, int val)
    {
        while((val > root->val && root->right != NULL) || (val < root->val && root->left != NULL))
        {
            if(val> root->val)
            root = root->right;
            else root = root->left;
        }
        if(val>root->val) root->right = new TreeNode(val);
        else root->left = new TreeNode(val);
    }
};

/*
class Solution
{
  public:
    vector<TreeNode *> TNs;

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder.at(0));
        TNs.push_back(root);
        for (int i = 1; i < preorder.size(); i++)
        {
            if (preorder.at(i) < TNs.back()->val)
            {
                TNs.back()->left = new TreeNode(preorder.at(i));
                TNs.push_back(TNs.back()->left);
            }
            else
            {
                int k = TNs.size() - 1;
                if (k == 0 || (k > 0 && TNs.at(k)->val > TNs.at(k - 1)->val))
                {
                    TNs.back()->right = new TreeNode(preorder.at(i));
                    TNs.push_back(TNs.back()->right);
                }
                else
                {
                    while (k > 0 && TNs.at(k - 1)->val < preorder.at(i) && TNs.at(k)->val < TNs.at(k - 1)->val)
                    {
                        TNs.erase(TNs.begin() + TNs.size() - 1);
                        k--;
                    }
                    TNs.back()->right = new TreeNode(preorder.at(i));
                    TNs.push_back(TNs.back()->right);
                }
            }
        }
        return root;
    }
};
*/
