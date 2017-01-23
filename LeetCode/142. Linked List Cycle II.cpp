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
    ListNode *detectCycle(ListNode *head) {
        hash<ListNode*, bool> m;
        auto p = head;
        while (p!=NULL)
        {
            if (m[p]==true)
                break;
            m[p] = true;
            p = p->next;
        }
        return p;
    }
};
