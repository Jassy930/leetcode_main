/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.37%)
 * Total Accepted:    38.7K
 * Total Submissions: 90.5K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 *       [-2,-1,-4, 0,-1, 1, 2, -3, 1],
 *       [1 , 3, 2, 5, 1, 2, 0, -1, 4]
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 *  -2 -1
 *  -2 -3
 *  -1 -3
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int sum = nums[0];
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = temp + nums[i] > nums[i] ? temp + nums[i] : nums[i];
            if (sum < temp)
                sum = temp;
        }
        return sum;
    }
};
