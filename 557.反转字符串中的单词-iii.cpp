/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.46%)
 * Total Accepted:    12.5K
 * Total Submissions: 19.6K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        int p=0;
        int q=0;
        for(q=0; q<s.size(); q++)
        {
            if(s.at(q)==' ')
            {
                reverse(s.begin()+p,s.begin()+q);
                p=q+1;
            }
        }
        reverse(s.begin()+p,s.end());
        return s;
    }
};

