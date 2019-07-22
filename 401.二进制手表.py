#
# @lc app=leetcode.cn id=401 lang=python3
#
# [401] 二进制手表
#
import itertools
class Solution:
    def readBinaryWatch(self, num: int):
        return ["%d:%.2d"%(sum(h),sum(m)) for i in range(num+1) for h in itertools.combinations([8,4,2,1], i) for m in itertools.combinations([32,16,8,4,2,1], num-i) if sum(h)<12 and sum(m)<60]

