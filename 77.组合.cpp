/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.74%)
 * Total Accepted:    7.9K
 * Total Submissions: 12K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
class Solution
{
  public:
    vector<vector<int>> out;
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> num;
        getc(num, 1, n, k);
        return out;
    }

    void getc(vector<int> &num, int nn, int n, int k)
    {
        if (k == 0)
        {
            out.push_back(num);
            return;
        }
        if (nn > n)
            return;
        getc(num, nn + 1, n, k);
        num.push_back(nn);
        getc(num, nn + 1, n, k - 1);
        num.erase(num.begin()+num.size()-1);
    }
};
