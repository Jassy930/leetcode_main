/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 设计循环双端队列
 *
 * https://leetcode-cn.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (24.22%)
 * Total Accepted:    3.3K
 * Total Submissions: 13.3K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： A = "ab", B = "ba"
 * 输出： true
 * 
 * 
 * 示例 2：
 * 
 * 输入： A = "ab", B = "ab"
 * 输出： false
 * 
 * 
 * 示例 3:
 * 
 * 输入： A = "aa", B = "aa"
 * 输出： true
 * 
 * 
 * 示例 4：
 * 
 * 输入： A = "aaaaaaabc", B = "aaaaaaacb"
 * 输出： true
 * 
 * 
 * 示例 5：
 * 
 * 输入： A = "", B = "aa"
 * 输出： false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A 和 B 仅由小写字母构成。
 * 
 * 
 */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        map<char,int> cset;
        int i=0;
        auto ii=A.begin();
        auto it=B.begin();
        for(; ii!=A.end() && it!=B.end(); ii++,it++)
        {
            if(*ii != *it)
            {
                i++;
                cset[*ii]++;
                cset[*it]--;
            }
        }
        // for(auto iii = cset.begin(); iii!= cset.end(); iii++)
        // {
        //     if(iii->second != 2) return false;
        // }
        // return true;
        if(i == 2 || i == 0) return true;
        else return false;
    }
};

