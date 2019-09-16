#
# @lc app=leetcode.cn id=415 lang=python3
#
# [415] 字符串相加
#
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        dig = max(len(num1), len(num2))
        ans=[]
        sum = 0
        for i in range(dig):
            if len(num1)> i:
                sum+=int(num1[-1-i])
            if len(num2)> i:
                sum+=int(num2[-1-i])
            ans.append(str(sum%10))
            sum = sum//10
        if sum!=0:
            ans.append(str(sum))
        return ''.join(ans)[::-1]


