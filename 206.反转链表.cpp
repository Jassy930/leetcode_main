/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (58.59%)
 * Total Accepted:    40K
 * Total Submissions: 68.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        stack<ListNode*> lns;
        while(head!=NULL)
        {
            lns.push(head);
            head = head->next;
        }
        ListNode* out = new ListNode(lns.top()->val);
        lns.pop();
        ListNode* p = out;
        while(!lns.empty())
        {
            p->next = new ListNode(lns.top()->val);
            lns.pop();
            p = p->next;
        }
        return out;
    }
};

