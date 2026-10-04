
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;
        while(curr!=NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* d1=new ListNode(-1);
        ListNode* t1=d1;
        ListNode* temp1=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2= reverseList(slow->next);
        slow->next = NULL;
        ListNode* temp2=head2;
        while(temp2!=NULL){
            ListNode* Next1 = temp1->next;
            ListNode* Next2 = temp2->next;

            t1->next=temp1;
            t1=temp1;
            // temp1=temp1->next;
            t1->next=temp2;
            t1=temp2;
            t1->next = Next1;
            // temp2=temp2->next;
            temp1 = Next1;
            temp2 = Next2;
        }
    }
};