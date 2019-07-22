#
# @lc app=leetcode.cn id=717 lang=python3
#
# [717] 1比特与2比特字符
#


class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        ans = True
        while i < len(bits):
            if bits[i] == 0:
                i += 1
                ans = True
            elif bits[i] == 1:
                i += 2
                ans = False
        return ans
