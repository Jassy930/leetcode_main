/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (69.01%)
 * Total Accepted:    16.6K
 * Total Submissions: 24K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<string> out;
    vector<string> generateParenthesis(int n)
    {
        string s="";
        gen(s, 0, 0, n);
        return out;
    }

    void gen(string s, int l, int r, int n)
    {
        if(l == n && r == n) out.push_back(s);
        else if(l>=r && l<=n)
        {
             gen(s+"(", l+1, r, n);
             gen(s+")", l, r+1, n);
        }
    }
};
