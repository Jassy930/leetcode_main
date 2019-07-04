#
# @lc app=leetcode.cn id=844 lang=python3
#
# [844] 比较含退格的字符串
#
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        a=""
        b=""
        for i in S:
            if i!='#':
                a+=i
            else:
                a=a[0:-1]
        for i in T:
            if i!='#':
                b+=i
            else:
                b=b[0:-1]
        return a==b

