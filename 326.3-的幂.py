#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3的幂
#
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 0:
            return False
        while n!=1:
            if n%3 == 0:
                n = n//3
            else:
                return False
        return True
        

