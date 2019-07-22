#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#
class Solution:
    def isPalindrome(self, s: str) -> bool:
        k = ""
        for i in s:
            if i.isalnum():
                k=k+i
        k=k.lower()
        if k == k[::-1]:
            return True
        else:
            return False

