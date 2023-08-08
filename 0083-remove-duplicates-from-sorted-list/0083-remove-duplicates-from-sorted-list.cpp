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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = head;
        if(!head || !head->next) return head;
        head= head->next;
        while(head){
            int cur= head ->val;
            int pre = prev->val;
            if(cur== pre){
                prev->next = head->next;
                
            }
            else
                prev = head;
                
            head= head->next;
             
        }
        
        return dummy->next;
        
    }
};