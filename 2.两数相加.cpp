/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.55%)
 * Total Accepted:    85K
 * Total Submissions: 261.1K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
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
    ListNode p = ListNode(1);

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        else addd(l1, l2, 0);
        return l1;
    }

    void addd(ListNode* l1, ListNode* l2, int boost){
        int b = 0;
        if(l2 == NULL && boost == 0) return;
        // else if(l2 == NULL && l1 == NULL && boost == 1)
        // {
        //     l1 = &p;
        //     return;
        // }
        else if(l2 == NULL)
        {
            l1->val+=1;
            if(l1->val>=10){
                l1->val = 0;
                addd(l1->next, l2, 1);
            }
            else return;
        }
        // else if(l1->next == NULL && l2->next != NULL){
        //     l1->val = l1->val + l2->val + boost;
        //     addd(l2->next, NULL, boost);
        // }
        else{
            l1->val = l1->val + l2->val + boost;
            if(l1->next == NULL && l2->next != NULL)
            {
                if(l1->val >= 10){
                    l1->val -= 10;
                    addd(l2->next, NULL, 1);
                }
                else addd(l2->next, NULL, 0);
            }
            if (l1->val >= 10)
            {
                if(l1->next == NULL && l2->next == NULL)
                {
                    l1->next = new ListNode(1);
                    l1->val -= 10;
                    return;
                }
                l1->val -= 10;
                b = 1;
            }
            addd(l1->next, l2->next, b);
        }

    }
};

