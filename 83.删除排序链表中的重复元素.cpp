/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.81%)
 * Total Accepted:    16.9K
 * Total Submissions: 38.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *p = head;
        ListNode *q = head;
        while (p != NULL)
        {
            p = p->next;
            if(p == NULL) break;
            if (p->val != q->val)
            {
                q = p;
            }
            else
            {
                while(p !=NULL && p->val == q->val)
                {
                    p = p->next;
                }
                q->next = p;
                q = q->next;
            }
        }
        // q->next = p;
        return head;
    }
};
