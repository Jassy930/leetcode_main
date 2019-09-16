#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        i=0
        k=1
        maxnum = 1
        while k<=len(s):
            if k-i == len(set(s[i:k])):
                maxnum = max(maxnum, k-i)
                k+=1
            else:
                i+=1
        return maxnum

        # nn = [0]*len(s)
        # nn[0] = 1
        # for i in range(1,len(s)):
        #     if s[i]!=s[i-1]:
        #         nn[i] = nn[i-1]+1
        #     else:
        #         nn[i] = 0
        # return max(nn)
