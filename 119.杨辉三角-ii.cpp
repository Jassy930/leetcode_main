/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (53.87%)
 * Total Accepted:    9.9K
 * Total Submissions: 18.3K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> out;
        if(rowIndex == 0) out.push_back(1);
        for (int i=0; i<rowIndex; i++)
        {
            if(i==0) out.push_back(1);
            long ss = out.back();
            out.push_back(ss*(rowIndex - i)/(i+1));
            // unsigned long long k=1;
            // for (int j=rowIndex; j>rowIndex-i; j--) {k*=j;}
            // for (int j=1; j<i+1; j++) {k/=j;}

            // out.push_back(k);
        }
        return out;
    }
};

