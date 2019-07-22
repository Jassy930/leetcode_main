#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        l = []
        while head!=None:
            l.append(head.val)
            head = head.next
        if l == l[::-1]:
            return True
        return False

