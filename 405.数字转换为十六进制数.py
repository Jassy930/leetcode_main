#
# @lc app=leetcode.cn id=405 lang=python3
#
# [405] 数字转换为十六进制数
#
class Solution:
    def toHex(self, num: int) -> str:
        return hex(num)[2:] if num >=0 else hex(2**32+num)[2:]

