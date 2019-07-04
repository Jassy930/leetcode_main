#
# @lc app=leetcode.cn id=788 lang=python3
#
# [788] 旋转数字
#


class Solution:
    def rotatedDigits(self, N: int) -> int:
        trans = {'0': '0', '1': '1', '2': '5',
                 '5': '2', '6': '9', '8': '8', '9': '6'}
        count = 0
        for i in range(N+1):
            c = 0
            for k in str(i):
                if k not in trans:
                    c += 1
            if c == 0 and i != int(''.join([trans[x] for x in str(i)])):
                count += 1
        return count
