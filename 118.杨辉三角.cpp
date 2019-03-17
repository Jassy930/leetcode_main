/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (59.70%)
 * Total Accepted:    16.1K
 * Total Submissions: 27.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> out;
        if(numRows == 0) return out;
        vector<int> a(1,1);
        out.push_back(a);
        for(int i=1; i< numRows; i++)
        {
            vector<int> b;
            for(int k=0;k<=i;k++)
            {
                if(k==0) b.push_back(out.at(i-1).at(0));
                else if(k==i) b.push_back(out.at(i-1).at(k-1));
                else b.push_back(out.at(i-1).at(k) + out.at(i-1).at(k-1));
            }
            out.push_back(b);
        }
        return out;
    }
};

