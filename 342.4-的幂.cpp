/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (44.20%)
 * Total Accepted:    5.5K
 * Total Submissions: 12.4K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0)
            return false;
        while ((n & 0x03) == 0)
        {
            n = n >> 2;
        }
        if (n == 1)
            return true;
        else
            return false;
    }
};

