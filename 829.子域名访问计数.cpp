/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 子域名访问计数
 *
 * https://leetcode-cn.com/problems/consecutive-numbers-sum/description/
 *
 * algorithms
 * Hard (24.62%)
 * Total Accepted:    1.1K
 * Total Submissions: 4.4K
 * Testcase Example:  '5'
 *
 * 给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: 2
 * 解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
 * 
 * 示例 2:
 * 
 * 
 * 输入: 9
 * 输出: 3
 * 解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
 * 
 * 示例 3:
 * 
 * 
 * 输入: 15
 * 输出: 4
 * 解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 * 
 * 说明: 1 <= N <= 10 ^ 9
 * 
 */
class Solution
{
  public:
    int consecutiveNumbersSum(int N)
    {
        if (N == 1)
            return 1;
        if (N == 2)
            return 1;

        int out = 1;

        for (int i=2; ; i++)
        {
            if((i+1)*i/2 > N) return out;
            if(((i+1)*i/2) % i == N % i) out++;
        }

        return out;
    }
};
