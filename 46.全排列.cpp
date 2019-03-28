/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.02%)
 * Total Accepted:    15.1K
 * Total Submissions: 22.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> out;
        if (nums.size() == 0)
            return out;
        vector<int> a;
        a.push_back(nums.at(0));
        out.push_back(a);
        for (int i = 1; i < nums.size(); i++)
        {
            vector<vector<int>> oo;
            for (int k = 0; k < out.size(); k++)
            {
                for (int j = 0; j < out.at(out.size()-1).size(); j++)
                {
                    vector<int> vv(out.at(k));
                    vv.insert(vv.begin()+j, nums.at(i));
                    oo.push_back(vv);
                }
                out.at(k).push_back(nums.at(i));
                oo.push_back(out.at(k));
            }
            out.clear();
            out = oo;
        }
        return out;
    }
};
