#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        flag = 0
        ans = 0
        lasttime = 0
        if len(prices)<2:
            return ans
        if prices[0]<=prices[1]:
            lasttime = prices[0]
            flag = 1
        for i in range(1,len(prices)-1):
            if flag == 0 and prices[i]<=prices[i+1] and prices[i]<=prices[i-1]:
                lasttime = prices[i]
                flag = 1
            elif flag == 1 and prices[i]>=prices[i+1] and prices[i]>=prices[i-1]:
                ans += prices[i]-lasttime
                flag = 0
        if prices[-1]>prices[-2] and flag == 1:
            ans+=prices[-1]-lasttime
        return ans

