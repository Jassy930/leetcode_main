/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 新21点
 *
 * https://leetcode-cn.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (62.68%)
 * Total Accepted:    7.2K
 * Total Submissions: 11.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个矩阵 A， 返回 A 的转置矩阵。
 * 
 * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> out;
        if (A.size() == 0)
            return out;
        for (int i = 0; i < A.at(0).size(); i++)
        {
            vector<int> vv;
            for (int k = 0; k < A.size(); k++)
            {
                vv.push_back(A.at(k).at(i));
            }
            out.push_back(vv);
        }
        return out;
    }
};
