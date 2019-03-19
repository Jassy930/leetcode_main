/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (54.61%)
 * Total Accepted:    7.1K
 * Total Submissions: 12.9K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */
class Solution
{
  public:
    char findTheDifference(string s, string t)
    {
        int a = 0;
        for (auto ii : s)
            a ^= ii;
        for (auto ii : t)
            a ^= ii;
        return (char)a;
    }
};
