#
# @lc app=leetcode.cn id=400 lang=python3
#
# [400] 第N个数字
#
class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        k = 0
        count = 0

        while count < n:
            k += 1
            count += 9 * 10**(k - 1) * k
        clip_num = n - count + 9 * 10**(k - 1) * k

        k_num = (clip_num - 1) / k
        k_end = (clip_num - 1) % k
        num = 10**(k - 1) + k_num

        return int(str(num)[k_end])

