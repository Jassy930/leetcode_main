#
# @lc app=leetcode.cn id=167 lang=python3
#
# [167] 两数之和 II - 输入有序数组
#
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        k = len(numbers)-1
        while numbers[i]+numbers[k] != target:
            if numbers[i]+numbers[k] <target:
                i+=1
            elif numbers[i]+numbers[k] > target:
                k-=1
        return [i+1,k+1]

