/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 超级回文数
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (71.48%)
 * Total Accepted:    3.4K
 * Total Submissions: 4.7K
 * Testcase Example:  '"IDID"'
 *
 * 给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
 * 
 * 返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
 * 
 * 
 * 如果 S[i] == "I"，那么 A[i] < A[i+1]
 * 如果 S[i] == "D"，那么 A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出："IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出："III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 输出："DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 1000
 * S 只包含字符 "I" 或 "D"。
 * 
 * 
 */
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> out;
        // if(S.size() == 0) return out;
        int m = 0;
        int n = S.size();
        for(int i=0; i<S.size(); i++)
        {
            if(S.at(i) == 'I')
            {
                out.push_back(m);
                m++;
            }
            else{
                out.push_back(n);
                n--;
            }
        }
        out.push_back(m);
        return out;
    }
};

