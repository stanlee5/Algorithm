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
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0), b(0);
        ListNode *p=&a,*q=&b,*it=head;
        
        while (it)
        {
            if (it->val < x)
            {
                p->next = it;
                p = p->next;
            }
            else
            {
                q->next = it;
                q = q->next;
            }
            it = it->next;
        }
        q->next = NULL;
        p->next = b.next;
        return a.next;
    }
};
