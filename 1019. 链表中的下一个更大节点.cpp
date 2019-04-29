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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> value;
        stack<int> index;
        map<int,int> outmap;
        vector<int> out;
        int i=0;
        if(head == NULL) return out;
        value.push(head->val);
        index.push(i++);
        head = head->next;
        
        while(head!=NULL || value.size()!=0)
        {
            if(head==NULL)
            {
                outmap[index.top()] = 0;
                value.pop();
                index.pop();
            }
            else if(value.size()!=0 && head->val > value.top())
            {
                // out.push_back(head->val);
                outmap[index.top()] = head->val;
                value.pop();
                index.pop();
            }
            else if(value.size() == 0 || (value.size()!=0 && head->val <= value.top()))
            {
                index.push(i++);
                value.push(head->val);
                head = head->next;
            }
        }
        for(auto mm=outmap.begin(); mm!= outmap.end(); mm++)
        {
            out.push_back(mm->second);
        }
        return out;
        
        
    }
};