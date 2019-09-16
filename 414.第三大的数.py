#
# @lc app=leetcode.cn id=414 lang=python3
#
# [414] 第三大的数
#
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        ans=[-9999999999, -9999999999, -9999999999]
        for i in nums:
            if i not in ans and i > ans[-1]:
                if i > ans[-2]:
                    if i > ans[-3]:
                        ans.insert(0,i)
                    else:
                        ans.insert(1,i)
                else:
                    ans.insert(2,i)
                ans.pop()

        if -9999999999 in ans:
            return ans[0]
        else:
            return ans[-1]


