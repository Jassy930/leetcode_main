#
# @lc app=leetcode.cn id=696 lang=python3
#
# [696] 计数二进制子串
#


class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        i = 0
        j = 0
        k = 0
        ans = 0

        while k < len(s):
            while j < len(s) and s[j] == s[i]:
                j += 1
            k = j
            while k < len(s) and s[j] == s[k]:
                k += 1
            ans += min(k-j, j-i)
            i = j
        return ans
