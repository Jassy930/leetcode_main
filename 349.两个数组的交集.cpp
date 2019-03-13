/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (60.31%)
 * Total Accepted:    14.6K
 * Total Submissions: 24.2K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> numcount;
        vector<int> out;
        for(int i=0; i<nums1.size(); i++)
        {
            numcount[nums1.at(i)]++;
        }
        for(int i=0; i<nums2.size(); i++)
        {
            if(numcount[nums2.at(i)]>0)
            {
                out.push_back(nums2.at(i));
                numcount[nums2.at(i)]=0;
            }
        }
        return out;
    }
};

