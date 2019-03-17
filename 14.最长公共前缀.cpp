/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.94%)
 * Total Accepted:    54.8K
 * Total Submissions: 170.4K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int n = strs.at(0).size();
        for(int i=0; i<strs.size(); i++)
        {
            n = min(n, (int)strs.at(i).size());
        }
        string s = "";

        for(int i=0; i<n; i++)
        {
            char c = strs.at(0).at(i);
            for(int k=1; k<strs.size(); k++)
            {
                if(strs.at(k).at(i) != c)
                {
                    goto OUT;
                }
            }
            s = s + c;
        }
        OUT:
        return s;
    }
};

