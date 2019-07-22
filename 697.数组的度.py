#
# @lc app=leetcode.cn id=697 lang=python3
#
# [697] 数组的度
#


class Solution:
    def findShortestSubArray(self, nums) -> int:
        dd = {}
        maxdu = 0
        maxlen = 0
        for i, num in enumerate(nums):
            if num not in dd:
                dd[num] = [i, i, 1]
            else:
                dd[num][1] = i
                dd[num][2] += 1
                if dd[num][2] > maxdu:
                    maxdu = dd[num][2]
                    maxlen = dd[num][1] - dd[num][0]
                if dd[num][2] == maxdu:
                    maxlen = min(maxlen, dd[num][1] - dd[num][0])
        return maxlen+1
