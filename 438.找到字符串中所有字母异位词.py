#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans=[]
        pp = list(p)
        pp.sort()
        pp = ''.join(pp)
        for i in range(len(s) - len(p)+1):
            aa = list(s[i:i+len(p)])
            aa.sort()
            aa = ''.join(aa)
            if aa == pp:
                ans.append(i)
        return ans
            

