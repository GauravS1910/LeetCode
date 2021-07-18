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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
            return head; 
        
        ListNode *dummy = new ListNode(-1); 
        dummy -> next = head; 
        
        ListNode* ans = NULL; 
        
        ListNode* cur = head; 
        
        int c = 0; 
        while(cur!=NULL)
        {
            c++; 
            cur = cur -> next; 
        }
        int n = c/k; 
        
        cur = head; 
        ListNode *prev = dummy , *next = NULL;  
        for(int i=0;i<n;i++)
        {
            cur = prev -> next; 
            next = cur -> next; 
            for(int j=1;j<k;j++)
            {
                cur -> next = next -> next; 
                next -> next = prev -> next; 
                prev -> next = next; 
                next = cur -> next; 
            }
            prev = cur;  
        }
        return dummy -> next;  
    }
};