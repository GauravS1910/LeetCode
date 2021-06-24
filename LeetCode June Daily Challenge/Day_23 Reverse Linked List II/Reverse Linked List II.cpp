/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) 
    {
        ListNode *cur , *temp , *prev , *s , *e; 
        cur = head; 
        temp = NULL;  
        for(int i=1;i<=l;i++)
        {
            s = temp; 
            temp = cur; 
            cur = cur -> next; 
        }
        prev = temp; 
        e = temp; 
        for(int i=l+1;i<=r;i++)
        {
            temp = cur; 
            cur = cur -> next; 
            temp -> next = prev; 
            prev = temp; 
        }
        if(s!=NULL)
            s -> next = temp; 
        else
            head = temp; 
        if(e)
            e -> next = cur; 
        return head; 
    }
};