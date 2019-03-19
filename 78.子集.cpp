/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (71.61%)
 * Total Accepted:    14.1K
 * Total Submissions: 19.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> o;
        out.push_back(o);
        for(auto i : nums)
        {
            vector<vector<int>> oo;
            for( int k=0; k<out.size(); k++)
            {
                vector<int> ot(out.at(k));
                ot.push_back(i);
                oo.push_back(ot);
            }
            out.insert(out.begin(), oo.begin(), oo.end());
        }
        return out;
    }
};


/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        if(nums.size() == 0) return out;
        int m = pow(2,nums.size());
        for(int i=0; i<m; i++)
        {
            vector<int> oo;
            for(int k=0; k<nums.size(); k++)
            {
                if(i&(1<<k)) oo.push_back(nums.at(k));
            }
            out.push_back(oo);
        }
        return out;
    }
};
*/
