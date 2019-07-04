#
# @lc app=leetcode.cn id=860 lang=python3
#
# [860] 柠檬水找零
#
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        money={5:0,10:0,20:0}
        for b in bills:
            if b == 5:
                money[5]+=1
            elif b == 10:
                if money[5]<1:
                    return False
                else:
                    money[5]-=1
                    money[10]+=1
            elif b == 20:
                if (money[5]<1 or money[10]<1) and money[5]<3:
                    return False
                elif money[10]<1:
                    money[5]-=3
                    money[20]+=1
                else:
                    money[5]-=1
                    money[10]-=1
                    money[20]+=1
        return True
