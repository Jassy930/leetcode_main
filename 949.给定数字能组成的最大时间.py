#
# @lc app=leetcode.cn id=949 lang=python3
#
# [949] 给定数字能组成的最大时间
#
class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        o=""
        nums=[]
        for i in itertools.permutations(''.join([str(x) for x in A]), 4):
            nums.append(int(''.join(i)))
        nums.sort()
        for i in nums[-1::-1]:
            if i < 2400 and (i%100)<60:
                return "{:0>2d}:{:0>2d}".format(i//100,i%100)
        return ""

