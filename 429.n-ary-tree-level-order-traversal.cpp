/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Easy (59.28%)
 * Total Accepted:    3.6K
 * Total Submissions: 6.1K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其层序遍历:
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总数不会超过 5000。
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
  public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> out;
        if(root == NULL) return out;
        vector<int> layer1;
        layer1.push_back(root->val);
        out.push_back(layer1);
        queue<Node*> nodeq;
        for(int i=0; i<root->children.size(); i++)
        {
            nodeq.push(root->children.at(i));
        }
        while(nodeq.size()!=0)
        {
            vector<int> layer;
            queue<Node*> nodeqnew;
            while(nodeq.size()!=0)
            {
                Node* p = nodeq.front();
                nodeq.pop();
                layer.push_back(p->val);
                for(int i=0; i<p->children.size(); i++)
                {
                    nodeqnew.push(p->children.at(i));
                }
            }
            out.push_back(layer);
            nodeq=nodeqnew;
        }
        return out;
    }
};
