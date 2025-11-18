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
        ListNode* t=head;
        int h=k;
        while(h && t!=NULL){
            t=t->next;
            h--;
        }
        if(h) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        for(int i=0;i<k;i++){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};