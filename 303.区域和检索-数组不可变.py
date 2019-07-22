#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#
class NumArray:

    def __init__(self, nums: List[int]):
        self.data = [(0,0)]
        for num in nums:
            self.data.append((num,num+self.data[-1][1]))

    def sumRange(self, i: int, j: int) -> int:
        return self.data[j+1][1]-self.data[i][1]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)

