#
# @lc app=leetcode.cn id=687 lang=python3
#
# [687] 最长同值路径
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    ans = 1
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.lu(root)
        return self.ans-1

    def lu(self, root):
        if root == None:
            return
        self.lu(root.left)
        self.lu(root.right)
        if root.left == None and root.right == None:
            root.vv=1
        elif root.left == None:
            if root.val == root.right.val:
                root.vv = root.right.vv+1
                self.ans = max(self.ans, root.vv)
            else:
                root.vv = 1
        elif root.right == None:
            if root.val == root.left.val:
                root.vv = root.left.vv+1
                self.ans = max(self.ans, root.vv)
            else:
                root.vv = 1
        else:
            if root.left.val == root.val and root.right.val == root.val:
                self.ans = max(self.ans,root.left.vv+root.right.vv+1)
                root.vv = max(root.left.vv,root.right.vv)+1
            elif root.left.val == root.val:
                root.vv = root.left.vv+1
                self.ans = max(self.ans, root.vv)
            elif root.right.val == root.val:
                root.vv = root.right.vv+1
                self.ans = max(self.ans, root.vv)
            else:
                root.vv = 1



