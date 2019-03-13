/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 打砖块
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (62.35%)
 * Total Accepted:    4.2K
 * Total Submissions: 6.7K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
 * 
 * 示例 1:
 * 
 * 
 * 输入: S = "loveleetcode", C = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 说明:
 * 
 * 
 * 字符串 S 的长度范围为 [1, 10000]。
 * C 是一个单字符，且保证是字符串 S 里的字符。
 * S 和 C 中的所有字母均为小写字母。
 * 
 * 
 */
class Solution
{
  public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> out(S.size(), S.size());
        for (int i = 0; i < S.size(); i++)
        {
            if (S.at(i) == C)
                out.at(i) = 0;
        }
        int k = -1 * S.size();
        for (int i = 0; i < out.size(); i++)
        {
            if (out.at(i) == 0)
            {
                k = i;
            }
            else
            {
                out.at(i) = i - k;
            }
        }
        k = 2 * S.size();
        for (int i = out.size() - 1; i >= 0; i--)
        {
            if (out.at(i) == 0)
            {
                k = i;
            }
            else
            {
                out.at(i) = min(out.at(i),k - i);
            }
        }
        return out;
    }
};
