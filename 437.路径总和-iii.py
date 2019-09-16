#
# @lc app=leetcode.cn id=437 lang=python3
#
# [437] 路径总和 III
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.back(root)
        print(root.ll)
        return root.ll.count(sum)


    def back(self, root):
        if root == None:
            return
        self.back(root.left)
        self.back(root.right)
        root.ll = []
        if root.left != None:
            root.ll = root.ll + root.left.ll
        if root.right != None:
            root.ll = root.ll + root.right.ll
        for i in range(len(root.ll)):
            root.ll.append(root.ll[i]+root.val)
        root.ll.append(root.val)
[3, -2, 6, 1, 3, 
1, 3, 2, 
8, 3, 11, 6, 8, 6, 8, 7, 5, 11, 8, -3, 13, 8, 16, 11, 13, 11, 13, 12, 18, 13, 21, 16, 18, 16, 18, 17, 15, 21, 18, 7, 10]'


