/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 长按键入
 *
 * https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (69.80%)
 * Total Accepted:    6K
 * Total Submissions: 8.7K
 * Testcase Example:  '[1,2,3,3]'
 *
 * 在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
 * 
 * 返回重复了 N 次的那个元素。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,3]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 输入：[2,1,2,5,3,2]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：[5,1,5,2,5,3,5,4]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length 为偶数
 * 
 * 
 */
class Solution
{
  public:
    int repeatedNTimes(vector<int> &A)
    {
        if(A.at(0) == A.at(2)) return A.at(0);
        else if(A.at(1) == A.at(3)) return A.at(1);
        else {
            for(int i=0;i<A.size(); i++)
            {
                if(A.at(i) == A.at(i+1))
                return A.at(i);
            }
        }
        return 0;
    }
};
