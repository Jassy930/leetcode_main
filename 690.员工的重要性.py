#
# @lc app=leetcode.cn id=690 lang=python3
#
# [690] 员工的重要性
#
"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees, id):
        ans = 0
        emp = {}
        for ee in employees:
            emp[ee.id] = [ee.importance, ee.subordinates]
        que = [id]
        while len(que) != 0:
            ans += emp[que[0]][0]
            que = que[1:]+emp[que[0]][1]
        return ans
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
